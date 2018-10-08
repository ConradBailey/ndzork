#ifndef ROOM_GOLDEN_DOME_HPP
#define ROOM_GOLDEN_DOME_HPP

#include "room.hpp"

#include <string>

class Golden_Dome : public Room {
public:
	Golden_Dome();
	std::string get_name();
	std::string get_descr();
	bool handle(Command c);
	void remove_permacloud();
private:
	std::string name = "The Golden Dome";
	bool permacloud = true;
};

#endif
