#ifndef ROOM_LA_FUN_HPP
#define ROOM_LA_FUN_HPP

#include "room.hpp"

#include <string>

class La_Fun : public Room {
public:
	La_Fun();
	std::string get_name();
	std::string get_descr();
	bool handle(Command c);
	void remove_permacloud();
private:
	std::string name = "La Fun";
	bool permacloud = true;
};

#endif
