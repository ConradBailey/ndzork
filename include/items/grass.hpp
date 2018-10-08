#ifndef ITEM_GRASS_HPP
#define ITEM_GRASS_HPP

#include "item.hpp"
#include "../game/game.hpp"
#include "../command.hpp"

class Grass : public Item {
public:
	std::string get_name();
	std::string get_full_name();
	std::string get_descr();
	bool is_takeable();
	bool handle(Command command);

private:
	std::string name = "grass";
	std::string full_name = "patch of grass";
	std::string descr = "The grass is perfectly manicured. It looks so soft and of level height. You kinda wanna touch it.";
};

#endif
