#ifndef ROOM_GROTTO_HPP
#define ROOM_GROTTO_HPP

#include "room.hpp"
#include "../command.hpp"
#include "../game/gameio.hpp"

#include <string>

class Grotto : public Room {
public:
	Grotto();
	std::string get_name();
	std::string get_descr();
	bool handle(Command c);
private:
	std::string name = "The Grotto";
	std::string description = "Everybody is really quiet. There's a cave with a bunch of candles burning softly inside.";

	bool look(Command c);
};

#endif
