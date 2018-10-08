#ifndef ROOM_GOD_QUAD_HPP
#define ROOM_GOD_QUAD_HPP

#include "room.hpp"

#include <string>

class God_Quad : public Room {
public:
	God_Quad();
	std::string get_name();
	std::string get_descr();
	bool handle(Command c);
private:
	std::string name = "God Quad";
	std::string description = "You're surrounded by tradition and immaculate, symmetrical landscaping. To the south you see the back of a figure with outstretched arms. To the north the golden dome gleams catholicly.";
};

#endif
