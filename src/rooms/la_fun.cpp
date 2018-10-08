#include "../../include/rooms/la_fun.hpp"

La_Fun::La_Fun() {
}

std::string La_Fun::get_name() {
	return name;
}

std::string La_Fun::get_descr() {
	std::string description = "The students call this place La Fun. The original, ancient name has been lost to the sands of time. The students here all look really ";
	if (permacloud) {
		description += "depressed.";
	}
	else {
		description += "happy!";
	}
	return description;
}

void La_Fun::remove_permacloud() {
	permacloud = false;
}

bool La_Fun::handle(Command c) {
	return Room::handle(c);
}
