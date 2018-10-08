#include "../../include/game/ndzork.hpp"

#include "../../include/game/gameio.hpp"

bool NDZork::look(Command /*c*/){
	return false;
}

bool NDZork::light(Command c){
	if (c.get_dobj() == nullptr) {
		print("Light what?\n");
		return true;
	}
	return false;
}

bool NDZork::go(Command c) {
	if (c.get_dobj() == nullptr) {
		print("You cannot go that way.\n");
		return true;
	}
	else {
		auto dir_table = player_location->get_dir_table();
		auto dir_lookup = dir_table.find(c.get_dobj()->get_name());
		if (dir_lookup != dir_table.end()) {
			Room *new_location = (*dir_lookup).second;
			player_location->remove_actor(player);
			player_location = new_location;
			player_location->add_actor(player);
			player_location->look(c);
			return true;
		}
		else {
			print("You can't go that way.\n\n");
			return true;
		}
	}

	return false;
}

bool NDZork::quit(Command /*c*/){
	print("Do you wish to leave the game? (y/n): ");
	std::string input(get_input_line());
	if ((input[0] == 'y' || input[0] == 'Y') && (input.length() == 1)) {
		lose_game();
	}
	else {
		print("Ok.\n");
	}
	return true;
}


bool NDZork::shake(Command /*c*/){
    return false;
}
bool NDZork::take(Command /*c*/){
	return false;
}

bool NDZork::put(Command /*c*/){
	return false;
}

bool NDZork::inv(Command /*c*/){
	return false;
}

bool NDZork::extinguish(Command /*c*/){
	return false;
}

bool NDZork::climb(Command /*c*/) {
	return false;
}

bool NDZork::touch(Command /*c*/) {
	print("It feels exactly as you would expect.\n");
	return true;
}
