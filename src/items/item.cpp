#include "../../include/items/item.hpp"
#include "../../include/rooms/room.hpp"
#include "../../include/game/gameio.hpp"

Item::~Item() {
	for (auto item : get_items()) {
		delete item;
	}
}

bool Item::handle(Command c) {
	std::string verb = c.get_verb();
	if (c.get_dobj() == this) {
		if (verb == "look") return look(c);
		else if (verb == "take") return take(c);
		else if (verb == "put") return put(c);
	}

	return Object::handle(c);
}

bool Item::look(Command /*c*/) {
	print(get_descr(), "\n");
	for (auto item : get_items()) {
		print("There is a ", item->get_name(), " here.\n");
	}
	return true;
}

bool Item::take(Command c) {
	// Sanity check
	if (!is_takeable()) {
		print("You cannot take that\n");
		return true;
	}

	// Find and remove item
	Room *room = c.get_room();
	for (Item *item : room->get_items()) {
		if (item == this) {
			room->remove_item(this);
			break;
		}
		for (Item *inner_item : item->get_items()) {
			if (inner_item == this) {
				item->remove_item(this);
				break;
			}
		}
	}

	// Move the item
	c.get_actor()->add_item(this);
	print("You took the ", this->get_full_name(), "\n");
	return true;
}

bool Item::put(Command c) {
	Item *dobj = static_cast<Item *>(c.get_dobj());
	if (dobj == nullptr) {
		print("Put what? And put it where?\n");
		return true;
	}

	// If an indirect object is not given, assume dropping the item on
	// the floor (i.e. give to the room)
	Object *iobj = c.get_iobj();
	if (c.get_iobj() == nullptr) {
		iobj = c.get_room();
	}

	if (!iobj->can_contain_items()) {
		print("You cannot put the ", dobj->get_full_name(), " in the ", iobj->get_full_name(), "\n");
		return true;
	}

	if (!c.get_actor()->check_item(dobj)) {
		print("How can you do anything with that when you do not have it?\n");
		return true;
	}

	c.get_actor()->remove_item(dobj);
	iobj->add_item(dobj);
	return true;
}
