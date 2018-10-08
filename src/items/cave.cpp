#include "../../include/items/cave.hpp"

#include "../../include/game/gameio.hpp"
#include "../../include/game/game.hpp"
#include "../../include/object.hpp"
#include "../../include/items/candle.hpp"

#include <string>

std::string Cave::get_name() {
	return name;
}

std::string Cave::get_descr() {
	return descr;
}

bool Cave::is_takeable() {
	return false;
}

bool Cave::can_contain_items() {
	return true;
}

bool Cave::handle(Command c) {
	std::string verb = c.get_verb();
	if (c.get_iobj() == this) {
		if (verb == "put") {
			Object *dobj = c.get_dobj();
			if (dobj->get_name() != "candle") {
				print("That does not go here!\n");
				return true;
			}

			Item::put(c);

			Candle *candle = static_cast<Candle *>(dobj);
			if (!candle->is_lit()) {
				print("You placed the unlit candle in the cave. It was a disappointing experience for everyone nearby.\n");
			}
			else {
				print("You placed the lit candle in the cave. The Virgin Mary appears to you and says, \"Never before has every holder been filled with a lit candle. This is really cool. For all your hard work, I will carry out your prayer and lift the perma-cloud that shrouds this magnificent campus. All of this university's athletic endeavors will be met with unrivaled success. All of USC's wins are hereby vacated and replaced with Notre Dame wins. Especially the national championships. Hail me!\" And she vanishes along with the perma-cloud and any happiness that USC thought it might know.");
				c.get_game()->win_game();
			}
			return true;
		}
	}

	return Item::handle(c);
}

