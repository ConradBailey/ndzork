#include "../include/command.hpp"
#include "../include/game/gameio.hpp"

Command::Command(std::string verb, Room *room, Actor *actor,
								 Object *dobj, Object *iobj, Game *game) :
	verb(verb), room(room), actor(actor),
	dobj(dobj), iobj(iobj), game(game)
{}

Game * Command::get_game() {
	return game;
}

std::string Command::get_verb() {
	return verb;
}

Room * Command::get_room() {
	return room;
}

Actor * Command::get_actor() {
	return actor;
}

Object * Command::get_dobj() {
	return dobj;
}

Object * Command::get_iobj() {
	return iobj;
}

