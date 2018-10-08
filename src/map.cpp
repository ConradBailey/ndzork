#include "../include/map.hpp"

Map::~Map() {
	for (Room *room : get_rooms()) {
		delete room;
	}
}

void Map::add_room(Room *r) {
	rooms.insert(r);
}

void Map::remove_room(Room *r) {
	rooms.erase(r);
}

Room * Map::find_room(std::string name) {
	for (auto room : rooms) {
		if (room->get_name() == name) return room;
	}

	return nullptr;
}

std::unordered_set<Room *> Map::get_rooms() {
	return rooms;
}
