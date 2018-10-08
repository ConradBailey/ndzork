#ifndef ACTOR_HPP
#define ACTOR_HPP

#include "../object.hpp"
#include "../items/item.hpp"
#include "../command.hpp"

#include <unordered_set>

class Actor : public Object {
public:
	virtual ~Actor();

	bool check_item(Item *item);
	bool check_item(std::string item_name);

	virtual bool handle(Command c);

protected:
	bool inventory();
};

#endif
