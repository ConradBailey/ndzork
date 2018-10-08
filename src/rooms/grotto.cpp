#include "../../include/rooms/grotto.hpp"

#include "../../include/items/cave.hpp"

Grotto::Grotto() {
	add_item(new Cave());
}

std::string Grotto::get_name() {
	return name;
}

std::string Grotto::get_descr() {
	return description;
}

bool Grotto::handle(Command c) {
	std::string verb = c.get_verb();
	if (c.get_dobj() == this) {
		if (verb == "look") return look(c);
	}

	return Room::handle(c);
}

bool Grotto::look(Command c) {
	print(get_name(), "\n");
	print(get_descr(), "\n");
	for (auto actor : get_actors()) {
		if (actor == c.get_actor()) continue;
		print("You can see ", actor->get_full_name(), " here.\n");
	}

	for (auto item : get_items()) {
		if (item->get_name() == "cave") {
			continue;
		}
		print("  There is a ", item->get_full_name(), " here.\n");
	}

	return true;
}
