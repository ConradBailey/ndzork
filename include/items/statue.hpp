#ifndef ITEM_STATUE_HPP
#define ITEM_STATUE_HPP

#include "item.hpp"
#include "../command.hpp"

class Statue : public Item {
public:
	std::string get_name();
	std::string get_descr();
	bool is_takeable();
	bool handle(Command command);

private:
	std::string name = "statue";
	std::string descr = "A pale green Jesus figure stands with his arms outstretched. The inscription reads \"VENITE AD ME OMNES\". That's Latin for something probably.";
};

#endif
