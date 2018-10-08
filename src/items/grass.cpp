#include "../../include/items/grass.hpp"

#include "../../include/game/gameio.hpp"

#include <string>

std::string Grass::get_name() {
	return name;
}

std::string Grass::get_full_name() {
	return full_name;
}

std::string Grass::get_descr() {
	return descr;
}

bool Grass::is_takeable() {
	return false;
}

bool Grass::handle(Command c) {
	std::string verb = c.get_verb();
	if (c.get_dobj() == this) {
		if (verb == "touch") {
			print("Oh no! Immediately upon touching the grass you are smote by an enormous lightning bolt. Nothing remains of you. No charred remains; not even a scorch mark. The only evidence of your passing is the traumatic testimony of those who have witnessed your divine retribution. You have transgressed. There will be no open casket for your mother to weep over.\n");
			c.get_game()->lose_game();
			return true;
		}
	}

	return Item::handle(c);
}

