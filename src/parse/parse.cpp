#include "../../include/parse/parse.hpp"

Parse::Parse(){
}

Parse::Parse(std::string verb, std::string dobj, std::string iobj) :
	verb(verb), dobj(dobj), iobj(iobj) {
}

std::string Parse::get_verb() {
	return verb;
}
std::string Parse::get_dobj() {
	return dobj;
}
std::string Parse::get_iobj() {
	return iobj;
}
