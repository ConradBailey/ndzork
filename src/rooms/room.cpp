#include "../../include/rooms/room.hpp"

#include "../../include/game/gameio.hpp"

#include <string>

Room::~Room() {
	for (auto item : get_items()) {
		delete item;
	}

	for (auto actor : get_actors()) {
		delete actor;
	}

	for (auto misc : get_miscs()) {
		delete misc;
	}
}

std::unordered_set<Actor *> Room::get_actors() {
	return actors;
}

std::unordered_set<Misc *> Room::get_miscs() {
	return miscs;
}

std::unordered_set<Room *> Room::get_adj_rooms() {
	return adj_rooms;
}

std::unordered_map<std::string, Room *> Room::get_dir_table() {
	return dir_table;
}

void Room::add_actor(Actor *actor) {
	actors.insert(actor);
}

void Room::add_adj_room(std::string dir, Room *room) {
	adj_rooms.insert(room);
	dir_table[dir] = room;
	add_misc(new Misc(dir));
}

void Room::add_misc(Misc *misc) {
	miscs.insert(misc);
}

void Room::remove_actor(Actor *actor) {
	actors.erase(actor);
}
void Room::remove_adj_room(Room *room) {
	adj_rooms.erase(room);
}

bool Room::handle(Command c) {
	std::string verb = c.get_verb();
	if (c.get_dobj() == this) {
		if (verb == "look") return look(c);
	}
	else if (c.get_dobj() == nullptr) {
		if (verb == "look") return look(c);
	}

	return Object::handle(c);
}

bool Room::look(Command c) {
	print(get_name(), "\n");
	print(get_descr(), "\n");
	for (auto actor : get_actors()) {
		if (actor == c.get_actor()) continue;
		print("You can see ", actor->get_full_name(), " here.\n");
	}

	for (auto item : get_items()) {
		print("  There is a ", item->get_full_name(), " here.\n");

		// This Block used to make every item list their contents
		// This behavior was not wanted for the bushes.
		/////// if (!item->get_items().empty()) {
		/////// 	print("The ", item->get_full_name(), " contains:\n");
		/////// 	for (auto inner_item : item->get_items()) {
		/////// 		print("  A ", inner_item->get_full_name(), "\n");
		/////// 	}
		/////// }
	}
	return true;
}
