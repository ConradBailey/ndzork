#ifndef MAP_HPP
#define MAP_HPP

#include "rooms/room.hpp"

#include <unordered_set>

class Map {
public:
	~Map();
	void add_room(Room *r);
	void remove_room(Room *r);
	Room *find_room(std::string name);
	std::unordered_set<Room *> get_rooms();
private:
	std::unordered_set<Room *> rooms;
};

#endif
