#include "../include/object.hpp"

Object::~Object() {
}

std::string Object::get_full_name() {
	return get_name();
}

bool Object::handle(Command /*c*/) {
	return false;
}

bool Object::can_contain_items() {
	return false;
}

std::unordered_set<Item *> Object::get_items() {
	return items;
}

void Object::add_item(Item *item) {
	items.insert(item);
}

void Object::remove_item(Item *item) {
	items.erase(item);
}
