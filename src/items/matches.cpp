#include "../../include/items/matches.hpp"
#include "../../include/game/gameio.hpp"

std::string Matches::get_name() {
	return name;
}

std::string Matches::get_full_name() {
	return full_name;
}

std::string Matches::get_descr() {
	std::string descr = "It looks like a regular box of matches\n";

	return descr;
}

bool Matches::is_takeable() {
	return true;
}

bool Matches::handle(Command c) {
	return Item::handle(c);
}
