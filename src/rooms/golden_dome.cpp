#include "../../include/rooms/golden_dome.hpp"

#include "../../include/items/candle.hpp"
#include "../../include/items/stairs.hpp"

Golden_Dome::Golden_Dome() {
	add_item(new Candle());
	add_item(new Stairs());
}

std::string Golden_Dome::get_name() {
	return name;
}

std::string Golden_Dome::get_descr() {
	std::string description =	"Before you lies the master of your fate: the University of Notre Dame administration building. Adorning the top is an enormous golden dome; the Jewel of South Bend.";
	if (permacloud) {
		description += " Since it is cloudy, the dome doesnt look all that shiny.";
	}
	else {
		description += " The permacloud has been lifted and the dome blazes forth with unparalleled glory.";
	}
	description +=  " From the east floats a vague smell of food that you cannot quite specify. To the west there's a hint of smoke in the air.";

	return description;
}

void Golden_Dome::remove_permacloud() {
	permacloud = false;
}

bool Golden_Dome::handle(Command c) {
	return Room::handle(c);
}
