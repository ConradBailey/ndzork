#include "../../include/items/stairs.hpp"

#include "../../include/game/gameio.hpp"

#include <string>

std::string Stairs::get_name() {
	return name;
}

std::string Stairs::get_full_name() {
	return full_name;
}

std::string Stairs::get_descr() {
	return descr;
}

bool Stairs::is_takeable() {
	return false;
}

bool Stairs::handle(Command c) {
	std::string verb = c.get_verb();
	if (c.get_dobj() == this) {
		if (verb == "touch" ||
				verb == "go" ||
				verb == "climb") {
			print("Oh no! You feel a weak, clammy hand on your shoulder. It's Father Jenkins. It appears he is attempting to seathe at you. He lands a soft punch into your eye socket. It doesn't really hurt, but you lose your balance and crack your skull open on the steps.\n\nYou wake up at Highland Park Hospital, naturally. You've been in a coma for 10 years. You were expelled. All of your friends graduated. They have families and careers. Donald Trump has achieved dictatorial control of the U.S. government. California sank.\n\nYou have no motor control; paralyzed you are a mind trapped in it's own body. Over the soft beeping of the heart monitor you hear your mother sobbing, \"I just wish I could've said goodbye...\" Then a voice that's unmistakably Jenkins, \"Well he said goodbye to his business degree a long time ago. Pull the plug doctor.\" An audible spark follows. The equipment has malfunctioned. You die a slow, agonizing death, and nobody even noticed because of the paralysis.\n\nDon't touch the steps\n");
			c.get_game()->lose_game();
			return true;
		}
	}

	return Item::handle(c);
}

