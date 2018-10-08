#include "../../include/items/stones.hpp"

#include "../../include/game/gameio.hpp"

std::string Stones::get_name() {
	return name;
}

std::string Stones::get_full_name() {
	return full_name;
}

std::string Stones::get_descr() {
	return descr;
}

bool Stones::is_takeable() {
	return false;
}

bool Stones::handle(Command c) {
	return Item::handle(c);
}

