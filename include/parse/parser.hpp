#ifndef PARSER_HPP
#define PARSER_HPP

#include "../map.hpp"
#include "parse.hpp"

#include <string>
#include <unordered_set>
#include <unordered_map>
#include <initializer_list>

class Parser {
public:
	Parser();
	Parser(Map *map);
	Parse parse(std::string input);
	void add_verb(std::string verb,
								std::initializer_list<std::string> synonyms);
private:
	void add_actor(std::string actor);
	void add_item(std::string item);
	void add_room(std::string room);
	void add_misc(std::string misc);

	std::unordered_map<std::string, std::string> syn2verb;
	std::unordered_set<std::string> verbs;
	std::unordered_set<std::string> actors;
	std::unordered_set<std::string> items;
	std::unordered_set<std::string> rooms;
	std::unordered_set<std::string> miscs;
};

#endif
