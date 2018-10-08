#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

class Object;
class Actor;
class Room;
class Action;
class Game;

class Command {
public:
	Command(std::string verb, Room *room, Actor *actor,
					Object *dobj, Object *iobj, Game *game);
	std::string get_verb();
	Game * get_game();
	Room * get_room();
	Actor * get_actor();
	Object * get_dobj();
	Object * get_iobj();

private:
	std::string verb;
	Room *room;
	Actor *actor;
	Object *dobj;
	Object *iobj;
	Game *game;
};

#endif
