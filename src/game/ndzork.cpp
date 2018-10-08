#include "../../include/game/ndzork.hpp"

#include "../../include/parse/parse.hpp"
#include "../../include/game/gameio.hpp"

#include "../../include/actors/luke.hpp"

#include "../../include/rooms/jesus_statue.hpp"
#include "../../include/rooms/main_circle.hpp"
#include "../../include/rooms/god_quad.hpp"
#include "../../include/rooms/golden_dome.hpp"
#include "../../include/rooms/grotto.hpp"
#include "../../include/rooms/la_fun.hpp"

#include <random>

NDZork::NDZork() : Game(new Jesus_Statue(),
												new Luke()),
									 score(0), moves(0) {
	map = build_map();
	parser = Parser(map);
	build_actions();
	move_number = 0;
}

NDZork::~NDZork() {
}

void NDZork::lose_game() {
	game_state = LOSE;
}

void NDZork::win_game() {
	Golden_Dome *golden_dome = static_cast<Golden_Dome *>(map->find_room("The Golden Dome"));
	golden_dome->remove_permacloud();

	La_Fun *la_fun = static_cast<La_Fun *>(map->find_room("La Fun"));
	la_fun->remove_permacloud();

	game_state = WIN;
}

Game::Game_State NDZork::loop() {
	Parse p;
	while(game_state == IN_PROGRESS) {
		p = parser.parse(get_input_line());

		Object *dobj = str2obj(p.get_dobj());
		Object *iobj = str2obj(p.get_iobj());
		Command command(p.get_verb(), player_location,
										player, dobj, iobj, this);

		handle(command);
	}

	return game_state;
}

void NDZork::handle(Command c) {
	// Actor
	if (c.get_actor()->handle(c)) {
		//demons();
		return;
	}

	// Indirect Object
	if (c.get_iobj() && c.get_iobj()->handle(c)) {
		c.get_room()->handle(c);
		//demons();
		return;
	}

	// Direct Object
	if (c.get_dobj() && c.get_dobj()->handle(c)) {
		c.get_room()->handle(c);
		//demons();
		return;
	}

	// Verb
	auto verb_lookup = verb2handler.find(c.get_verb());
	if (verb_lookup != verb2handler.end()) {
		auto handler = (*verb_lookup).second;
		if ((this->*handler)(c)) {
			c.get_room()->handle(c);
			//demons();
			return;
		}
	}

	// Room
	if (c.get_room()->handle(c)) {
		//demons();
		return;
	}

	// Background Tasks
	//demons();

	// Nobody handled it completely
	print("I don't know how to do that\n");
}

Map * NDZork::build_map() {
	Map *map = new Map();
	spawn_point->add_actor(player);
	map->add_room(spawn_point);

	Room * jesus_statue = spawn_point;

	// Formula for adding a new room to the map
	Room * mainCircle = new Main_Circle();
	map->add_room(mainCircle);

	jesus_statue->add_adj_room("south", mainCircle);
	mainCircle->add_adj_room("north", jesus_statue);

	Room *god_quad = new God_Quad();
	map->add_room(god_quad);
	jesus_statue->add_adj_room("north", god_quad);
	god_quad->add_adj_room("south", jesus_statue);

	Room *golden_dome = new Golden_Dome();
	map->add_room(golden_dome);
	god_quad->add_adj_room("north", golden_dome);
	golden_dome->add_adj_room("south", god_quad);

	Room *grotto = new Grotto();
	map->add_room(grotto);
	golden_dome->add_adj_room("west", grotto);
	grotto->add_adj_room("east", golden_dome);

	Room *la_fun = new La_Fun();
	map->add_room(la_fun);
	golden_dome->add_adj_room("east", la_fun);
	la_fun->add_adj_room("west", golden_dome);

	return map;
}

void NDZork::build_actions() {
	add_handler("look", {"describe", "examine"}, &NDZork::look);
	add_handler("quit", {"q", "goodbye"}, &NDZork::quit);
	add_handler("light", &NDZork::light);
	add_handler("take", &NDZork::take);
	add_handler("put", {"place","drop"},  &NDZork::put);
	add_handler("inv", {"items", "inventory"}, &NDZork::inv);
	add_handler("extinguish", {"extenguish", "putout"}, &NDZork::extinguish);
	add_handler("go", { "travel", "walk", "run", "dance", "slither", "shimmy", "move", "logroll", "crawl", "moonwalk", "apparate", "fly", "materialize"}, &NDZork::go);
	add_handler("shake", &NDZork::shake);
	add_handler("touch", &NDZork::touch);
	add_handler("climb", &NDZork::climb);
}

void NDZork::add_handler(std::string verb,
												 std::initializer_list<std::string> synonyms,
												 bool(NDZork::*handler)(Command command))
{
	verb2handler[verb] = handler;
	parser.add_verb(verb, synonyms);
	for (auto syn : synonyms) {
		verb2handler[syn] = handler;
	}
}

void NDZork::add_handler(std::string verb,
												 bool(NDZork::*handler)(Command command))
{
	add_handler(verb, {}, handler);
}

void NDZork::demons() {

}
