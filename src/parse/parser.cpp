#include "../../include/parse/parser.hpp"
#include "../../include/rooms/room.hpp"
#include "../../include/items/item.hpp"
#include "../../include/actors/actor.hpp"

#include <string>
#include <sstream>

Parser::Parser() {
}

Parser::Parser(Map *map) {
	// Get room names from map
	for (auto room : map->get_rooms()) {
		add_room(room->get_name());

		// Get item names from room
		for (auto item : room->get_items()) {
			add_item(item->get_name());
			for (auto inner_item : item->get_items()) {
				add_item(inner_item->get_name());
			}
		}

		// Get Miscs (e.g. directions) from room
		for (auto misc : room->get_miscs()) {
			add_misc(misc->get_name());
		}

		// Get actor names from room
		for (auto actor : room->get_actors()) {
			add_actor(actor->get_name());
			// Get item names from actor
			for (auto item : actor->get_items()) {
				add_item(item->get_name());
				for (auto inner_item : item->get_items()) {
					add_item(inner_item->get_name());
				}
			}
		}
	}
}

Parse Parser::parse(std::string input) {
	std::string verb, dobj, iobj;
	std::stringstream words(input);
	std::string word;

	while (words >> word) {
		if (verbs.find(word) != verbs.end()) {
			verb = syn2verb[word];
			break;
		}
	}

	while (words >> word) {
		if (actors.find(word) != actors.end()) {
			dobj = word;
			break;
		}
		else if (items.find(word) != items.end()) {
			dobj = word;
			break;
		}
		else if (rooms.find(word) != rooms.end()) {
			dobj = word;
			break;
		}       
		else if (miscs.find(word) != miscs.end())  {
            dobj = word;
            break;
        }
	}

	while (words >> word) {
		if (actors.find(word) != actors.end()) {
			iobj = word;
			break;
		}
		else if (items.find(word) != items.end()) {
			iobj = word;
			break;
		}
		else if (rooms.find(word) != rooms.end()) {
			iobj = word;
			break;
		}
	}

	return Parse(verb, dobj, iobj);
}

void Parser::add_verb(std::string verb,
											std::initializer_list<std::string> synonyms)
{
	verbs.insert(verb);
	syn2verb[verb] = verb;
	for (auto syn : synonyms) {
		verbs.insert(syn);
		syn2verb[syn] = verb;
	}
}

void Parser::add_actor(std::string actor) {
	actors.insert(actor);
}

void Parser::add_item(std::string item) {
	items.insert(item);
}

void Parser::add_room(std::string room) {
	rooms.insert(room);
}

void Parser::add_misc(std::string misc) {
    miscs.insert(misc);
}
