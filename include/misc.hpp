#ifndef MISC_HPP
#define MISC_HPP

#include "command.hpp"
#include "object.hpp"

#include <string>
#include <unordered_set>
#include <unordered_map>

class Misc : public Object {
public:
	Misc(std::string name);
	~Misc();

	std::string get_name();
	std::string get_descr();

	void add_misc(Misc *misc);
	void remove_misc(Misc *misc);
 	std::unordered_set<Misc *> get_miscs();

	bool handle(Command command);

private:
	std::string name;
	std::unordered_set<Misc *> miscs;


};

#endif
