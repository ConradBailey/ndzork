#ifndef ITEM_HPP
#define ITEM_HPP

#include "../command.hpp"
#include "../object.hpp"

#include <unordered_set>

class Item : public Object {
public:
	virtual ~Item();
	virtual bool is_takeable() = 0;
	virtual bool handle(Command command);

protected:
	virtual bool look(Command c);
	virtual bool take(Command c);
	virtual bool put(Command c);
};

#endif
