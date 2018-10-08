#include "../../include/items/bushes.hpp"
#include "../../include/items/matches.hpp"
#include "../../include/game/gameio.hpp"

Bushes::Bushes() {
	add_item(new Matches());
}

std::string Bushes::get_name() {
	return name;
}

std::string Bushes::get_full_name() {
	return full_name;
}

std::string Bushes::get_descr() {
	return descr;
}

bool Bushes::is_takeable() {
	return false;
}

bool Bushes::can_contain_items() {
	return true;
}

bool Bushes::handle(Command c) {
	std::string verb = c.get_verb();
	if (c.get_dobj() == this) {
		if (verb == "look") return look(c);
	}
	return Item::handle(c);
}

bool Bushes::look(Command /*c*/) {
	print(descr);
	if (!get_items().empty()) {
		print("\nUpon closer inspection you see what's hidden through the leaves:\n");
		for (auto item : get_items()) {
			print("  A ", item->get_full_name(), "\n");
		}
	}

	return true;
}
