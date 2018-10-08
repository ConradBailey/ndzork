#ifndef ITEM_MATCHES_HPP
#define ITEM_MATCHES_HPP

#include "item.hpp"
#include "../command.hpp"
#include "../../include/actors/actor.hpp"
#include "../../include/rooms/room.hpp"

class Matches : public Item {
public:
	std::string get_name();
	std::string get_full_name();
	std::string get_descr();
	bool is_takeable();
	bool handle(Command command);

private:
	std::string name = "matches";
	std::string full_name = "box of matches";

	//Actions
	bool light();
};

#endif
