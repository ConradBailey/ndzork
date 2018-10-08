#include "include/game/ndzork.hpp"
#include "include/game/gameio.hpp"


int main() {
	print("You are a Notre Dame student and it is the last week of April. The South Bend permacloud has stayed looming over the campus for months now, leaving a never-ending impression of winter. The sun hasn’t been seen since the fall semester and campus life is deteriorated. You start wondering if there’s a way to lift this curse before finals week where you think most students will lose their minds. You begin wandering around campus, looking for a hint, a sign, any sort of clue to help you fix your school. Going from building to building, you find nothing. Exhausted, stressed, and depressed from your lack of vitamin D, you sit down on the ring of stones surrounding Jesus and toss him a prayer. Unexpectedly, you slip from your seat as the stones are loose. You look at the stones and read...\n\n  il y a un moyen d\'éclairer le monde\n\nWhich roughly translates to:\n\"There is one way to light the world\"\n\nLuckily, that one semester of French you took to fulfill a college requirement hasn’t completely left you and you finally see the light at the end of the tunnel.\n\nYou can save the school.\n");
	NDZork ndzork;
	if (ndzork.loop() == NDZork::WIN) {
		return 0;
	}
	return 1;
}
