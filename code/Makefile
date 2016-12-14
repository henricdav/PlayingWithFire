#
# Makefile
#

# SFML
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
INCLUDES = -I${SFML_ROOT}/include -L${SFML_ROOT}/lib

# Diagnosmeddelanden från kompilatorn (g++) filtreras av gccfilter.
CCC = g++

# Kompilatorflaggor, lägg till '-g' om kompilering för avlusning ska göras.
CCFLAGS += -std=c++14 -Wpedantic -Wall -Wextra -Werror #-Weffc++

# Preprocessorflaggor, -I lägger till en filkatalog i inkluderingssökvägen.
# CPPFLAGS += -I$(CODE)

# Objektkodsmoduler som ingår i det kompletta spelet
OBJECTS = playingwithfire.o Highscore.o  Menu.o GameEngine.o Object.o Character.o Bomb.o Map.o GameMusic.o

# Huvudmål - skapas med kommandot 'make' eller 'make playingwithfire'.
playingwithfire: $(OBJECTS) Makefile
	$(CCC) $(INCLUDES) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o playingwithfire.game $(OBJECTS) $(LIBS)

map_test: Map.o map_test.cc
	$(CCC) $(INCLUDES) $(CPPFLAGS) $(CCFLAGS) Map.o map_test.cc -o map_test.game $(LIBS)

# Delmål (flaggan -c avbryter innan länkning, objektkodsfil erhålls)
playingwithfire.o: playingwithfire.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c playingwithfire.cc

Highscore.o: Highscore.h Highscore.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Highscore.cc

Menu.o: Menu.h Menu.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Menu.cc

GameEngine.o: GameEngine.h GameEngine.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c GameEngine.cc

Object.o: Object.h Object.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Object.cc

Character.o: Character.h Character.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Character.cc

Bomb.o: Bomb.h Bomb.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Bomb.cc

Map.o: Map.h Map.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Map.cc

GameMusic.o: GameMusic.h GameMusic.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c GameMusic.cc


# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o *.gch core

# 'make zap' tar även bort det körbara programmet och reservkopior (filer
# som slutar med tecknet '~').
zap: clean
	@ \rm -rf playingwithfire.game *~

# Se upp vid eventuell ändring, '*' får absolut inte finnas för sig!!!
#
# '@' medför att kommandot inte skrivs ut på skärmen då det utförs av make.
# 'rm' är ett alias för 'rm -i' på IDA:s system, '\rm' innebär att "original-
# versionen", utan flaggan '-i', används.
