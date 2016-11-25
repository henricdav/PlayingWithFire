#
# Makefile för kalkylatorn, nivå G, GNU GCC (g++)
#
# Filkataloger där andra delar av programet finns.
# CODE = code

# SFML
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Diagnosmeddelanden från kompilatorn (g++) filtreras av gccfilter.
CCC = g++

# Kompilatorflaggor, lägg till '-g' om kompilering för avlusning ska göras.
CCFLAGS += -g -std=c++11 #-Wpedantic -Wall -Wextra -Werror -Weffc++

# Preprocessorflaggor, -I lägger till en filkatalog i inkluderingssökvägen.
# CPPFLAGS += -I$(CODE)

# Objektkodsmoduler som ingår i den kompletta kalkylatorn.
OBJECTS = playingwithfire.o Menu.o GameEngine.o

# Huvudmål - skapas med kommandot 'make' eller 'make kalkylator'.
playingwithfire: $(OBJECTS) Makefile
	$(CCC) $(CPPFLAGS) $(CCFLAGS) $(LDFLAGS) -o playingwithfire $(OBJECTS) $(LIBS)

# menu_test: test_main.o Expression_Tree.o $(EXPRESSION)/expression_tree-test.cc
# 	$(CCC) $(CPPFLAGS) $(CCFLAGS) -g test_main.o Expression_Tree.o Variable_Table.o $(EXPRESSION)/expression_tree-test.cc -o expression_tree_test
#
# expression_test: test_main.o Expression.o $(EXPRESSION)/expression-test.cc Expression_Tree.o
# 	$(CCC) $(CPPFLAGS) $(CCFLAGS) test_main.o Expression.o Expression_Tree.o Variable_Table.o $(EXPRESSION)/expression-test.cc -o expression_test
#
# variable_test: test_main.o Variable_Table.o variable_test.cc Variable_Table.o
# 	$(CCC) $(CPPFLAGS) $(CCFLAGS) test_main.o Variable_Table.o variable_test.cc -o variable_test

# Delmål (flaggan -c avbryter innan länkning, objektkodsfil erhålls)
playingwithfire.o: playingwithfire.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c playingwithfire.cc

Menu.o: Menu.h Menu.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Menu.cc

GameEngine.o: GameEngine.h GameEngine.cc
	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c GameEngine.cc



# Expression.o: $(EXPRESSION)/Expression.h $(EXPRESSION)/Expression.cc
# 	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c $(EXPRESSION)/Expression.cc
#
# Expression_Tree.o: $(EXPRESSION)/Expression_Tree.h $(EXPRESSION)/Expression_Tree.cc
# 	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c $(EXPRESSION)/Expression_Tree.cc
#
# Variable_Table.o: Variable_Table.h Variable_Table.cc
# 		$(CCC) $(CPPFLAGS) $(CCFLAGS) -c Variable_Table.cc
#
# test_main.o: $(EXPRESSION)/test_main.cc
# 	$(CCC) $(CPPFLAGS) $(CCFLAGS) -c $(EXPRESSION)/test_main.cc

# 'make clean' tar bort objektkodsfiler och 'core' (minnesdump).
clean:
	@ \rm -rf *.o *.gch core

# 'make zap' tar även bort det körbara programmet och reservkopior (filer
# som slutar med tecknet '~').
zap: clean
	@ \rm -rf playingwithfire *~

# Se upp vid eventuell ändring, '*' får absolut inte finnas för sig!!!
#
# '@' medför att kommandot inte skrivs ut på skärmen då det utförs av make.
# 'rm' är ett alias för 'rm -i' på IDA:s system, '\rm' innebär att "original-
# versionen", utan flaggan '-i', används.
