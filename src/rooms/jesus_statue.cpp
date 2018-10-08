#include "../../include/rooms/jesus_statue.hpp"
#include "../../include/items/candle.hpp"
#include "../../include/items/stones.hpp"
#include "../../include/items/matches.hpp"
#include "../../include/items/statue.hpp"

Jesus_Statue::Jesus_Statue() {
	add_item(new Stones());
	add_item(new Statue());
}

std::string Jesus_Statue::get_name() {
	return name;
}

std::string Jesus_Statue::get_descr() {
	return description;
}

bool Jesus_Statue::handle(Command c) {
	return Room::handle(c);
}
