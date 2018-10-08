#include "../../include/game/game.hpp"

Game::Game(Room *sp,
					 Actor *p) :
	spawn_point(sp),
	player(p),
	player_location(spawn_point)
{
}

// Can't build map here! Damn!
Game::~Game() {
	delete map;
}

Object * Game::str2obj(std::string s) {
	for (auto item : player_location->get_items()) {
		if (item->get_name() == s) {
			return item;
		}
		for (auto inner_item : item->get_items()) {
			if (inner_item->get_name() == s) {
				return inner_item;
			}
		}
	}

	for (auto misc : player_location->get_miscs()) {
		if (misc->get_name() == s) {
			return misc;
		}
	}

	for (auto actor : player_location->get_actors()) {
		if (actor->get_name() == s) {
			return actor;
		}
		for (auto item : actor->get_items()) {
			if (item->get_name() == s) {
				return item;
			}
			for (auto inner_item : item->get_items()) {
				if (inner_item->get_name() == s) {
					return inner_item;
				}
			}
		}
	}

	return nullptr;
}

