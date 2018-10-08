#ifndef ITEM_CAVE_HPP
#define ITEM_CAVE_HPP

#include "item.hpp"
#include "../command.hpp"

class Cave : public Item {
public:
	std::string get_name();
	std::string get_descr();
	bool is_takeable();
	bool can_contain_items();
	bool handle(Command command);

private:
	std::string name = "cave";
	std::string descr = "The place is nearly filled with candles. All have been lit, each carrying the weight of a prayer. There are no more to light, but one empty spot remains.";
};

#endif
