#include "../../include/actors/actor.hpp"
#include "../../include/game/gameio.hpp"

Actor::~Actor() {
	for (auto item : get_items()) {
		delete item;
	}
}

//checks if Actor has the item in inventory; item version
bool Actor::check_item(Item *item){
	for (auto it: get_items()){
		if (it == item){
			return true;
		}
	}
	return false;
}

//checks if Actor has the item in inventory; string version
bool Actor::check_item(std::string item_name){
	for(auto it: get_items()){
		if(it->get_name() == item_name){
			return true;
		}
	}
	return false;
}

bool Actor::handle(Command c) {
	std::string verb = c.get_verb();
	if(verb == "inv") return inventory();

	return Object::handle(c);
}

bool Actor::inventory() {
	if(get_items().empty()){
		print("You have nothing in your inventory\n");
		return true;
	}

	print("Here is your inventory\n");
	for(auto it : get_items()){
		print("\t", it->get_name(), "\n");
	}

	return true;
}

