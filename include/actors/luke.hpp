#ifndef LUKE_HPP
#define LUKE_HPP

#include "../command.hpp"
#include "actor.hpp"

class Luke : public Actor {
public:
	Luke();
	std::string get_name();
	std::string get_descr();
	bool handle(Command c);
private:
	std::string name = "Luke";
};

#endif
