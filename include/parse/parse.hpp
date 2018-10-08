#ifndef PARSE_HPP
#define PARSE_HPP

#include <string>

class Parse {
public:
	Parse();
	Parse(std::string verb, std::string dirobj, std::string indobj);
	std::string get_verb();
	std::string get_dobj();
	std::string get_iobj();
private:
	std::string verb;
	std::string dobj;
	std::string iobj;
};

#endif
