#include "../../include/rooms/god_quad.hpp"

#include "../../include/items/grass.hpp"

God_Quad::God_Quad() {
	add_item(new Grass());
}

std::string God_Quad::get_name() {
	return name;
}

std::string God_Quad::get_descr() {
	return description;
}

bool God_Quad::handle(Command c) {
	return Room::handle(c);
}
