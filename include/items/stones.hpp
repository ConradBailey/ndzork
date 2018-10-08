#ifndef ITEM_STONES_HPP
#define ITEM_STONES_HPP

#include "item.hpp"
#include "../command.hpp"

class Stones : public Item {
public:
	std::string get_name();
	std::string get_full_name();
	std::string get_descr();
	bool is_takeable();
	bool handle(Command command);

private:
	std::string name = "stones";
	std::string descr = "These are the stones that fell off the Jesus Statue enclosement. \nThey say \"il y un moyen d\'eclairer le monde\". \nFrom your semester in French, it translates to \"there is one way to light the world\".";
	std::string full_name = "pile of stones";
};

#endif
