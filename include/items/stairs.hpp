#ifndef ITEM_STAIRS_HPP
#define ITEM_STAIRS_HPP

#include "item.hpp"
#include "../game/game.hpp"
#include "../command.hpp"

class Stairs : public Item {
public:
	std::string get_name();
	std::string get_full_name();
	std::string get_descr();
	bool is_takeable();
	bool handle(Command command);

private:
	std::string name = "stairs";
	std::string full_name = "set of stairs";
	std::string descr = "The stairs are of pure marble. They look inviting. Perhaps they lead somewhere important?\n";
};

#endif
