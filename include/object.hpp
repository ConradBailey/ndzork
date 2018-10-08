#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "command.hpp"

#include <string>
#include <unordered_set>

class Item;

class Object {
public:
	virtual ~Object();
	virtual std::string get_name() = 0;
	virtual std::string get_full_name();
	virtual std::string get_descr() = 0;
	virtual bool handle(Command command);

	virtual bool can_contain_items();
	virtual void add_item(Item *item);
	virtual void remove_item(Item *item);
	virtual std::unordered_set<Item *> get_items();

protected:
	std::unordered_set<Item *> items;
	bool put(Command c);
	bool take(Command c);
};

#endif
