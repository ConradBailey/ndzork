#include "../../include/actors/luke.hpp"

Luke::Luke() {
}

std::string Luke::get_name() {
	return name;
}

std::string Luke::get_descr() {
	return "That's difficult unless your eyes are prehensile";
}

bool Luke::handle(Command c) {
	return Actor::handle(c);
}
