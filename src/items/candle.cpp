#include "../../include/items/candle.hpp"
#include "../../include/game/gameio.hpp"

std::string Candle::get_name() {
	return name;
}

std::string Candle::get_descr() {
	std::string descr;
	if (!is_lit()) {
		return "The "+get_name()+" is unlit.";
	}
	else {
		descr = "The "+get_name()+" is lit.";
	}

	return descr;
}

bool Candle::is_takeable() {
	if (is_lit()) {
		print("The candle is burning and too dangerous to touch!\n");
		return false;
	}
	return true;
}

bool Candle::is_lit() {
	return lit;
}

bool Candle::handle(Command c) {
	std::string verb(c.get_verb());
	if (c.get_dobj() == this) {
		if (verb == "light") return light(c);
		else if (verb == "extinguish") return extinguish();
	}

	return Item::handle(c);
}

bool Candle::extinguish(){
	if(is_lit()){
		print("You extinguish the candle\n");
		lit = false;
		return true;
	} else {
		print("The candle is not lit\n");
		return true;
	}
}

bool Candle::light(Command c) {
	//check if indirect object
	auto iobj = c.get_iobj();
	auto actor = c.get_actor();
	if(iobj == nullptr){
		print("Light the candle with what?\n");
		return true;
	} else if (iobj->get_name() == "matches"){
		if(actor->check_item(iobj->get_name())){ //actor has matches
			//lighting the candle
			if (is_lit()) {
				print("The candle is already lit.\n");
				return true;
			}
			else {
				lit = true;
				print("Lit the candle.\n");
				return true;
			}
		} else {
			print("You do not have any matches\n");
			return true;
		}
	} else {
		print("You cannot do that\n");
		return true;
	}
}
