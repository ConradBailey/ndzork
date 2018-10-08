CXX=g++ -lreadline -lcurses -std=gnu++11 -Wall -Wextra -Wpedantic -Wfatal-errors -O0

all: ndzork

PARSER=src/parse/parser.o src/parse/parse.o
OBJECTS=src/map.o src/game/gameio.o src/game/game.o src/object.o src/rooms/room.o src/items/item.o src/actors/actor.o src/command.o src/misc.o
GAME=src/game/ndzork.o src/game/ndzork_actions.o
ITEMS=src/items/candle.o src/items/stones.o src/items/matches.o src/items/statue.o src/items/bushes.o src/items/grass.o src/items/stairs.o src/items/cave.o
ACTORS=src/actors/luke.o
ROOMS=src/rooms/jesus_statue.o src/rooms/main_circle.o src/rooms/god_quad.o src/rooms/golden_dome.o src/rooms/grotto.o src/rooms/la_fun.o

ndzork: main.o $(OBJECTS) $(GAME) $(ROOMS) $(ITEMS) $(ACTORS) $(PARSER)
	$(CXX) $^ -o $@

%.o: %.cpp
	$(CXX) -c $< -o $@

clean:
	rm ndzork main.o $(OBJECTS) $(GAME) $(ROOMS) $(ITEMS) $(ACTORS) $(PARSER)
