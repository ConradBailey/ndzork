#include "../include/misc.hpp"

#include "../include/game/gameio.hpp"

Misc::Misc(std::string name) : name(name) {
}

Misc::~Misc() {
	for (auto misc : get_miscs()) {
		delete misc;
	}
}

std::string Misc::get_name() {
	return name;
}

std::string Misc::get_descr() {
	return "How can I possibly do that?";
}

std::unordered_set<Misc *> Misc::get_miscs() {
	return miscs;
}

void Misc::add_misc(Misc *misc) {
	miscs.insert(misc);
}

void Misc::remove_misc(Misc *misc) {
	miscs.erase(misc);
}

bool Misc::handle(Command c) {
	return Object::handle(c);
}
