#ifndef ITEM_BUSHES_HPP
#define ITEM_BUSHES_HPP

#include "item.hpp"
#include "../command.hpp"

class Bushes : public Item {
public:
	Bushes();
	std::string get_name();
	std::string get_full_name();
	std::string get_descr();
	bool is_takeable();
	bool can_contain_items();
	bool handle(Command command);

private:
	std::string name = "bushes";
	std::string full_name = "hedge of bushes";
	std::string descr = "The bushes are neatly trimmed.";

	bool look(Command c);
};

#endif
