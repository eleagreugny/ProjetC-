all : main

main : main.o Bacterie.o Environnement.o Simulation.o Case.o
	g++ main.o Bacterie.o Environnement.o Simulation.o Case.o -o main

main.o : main.cpp Bacterie.h Environnement.h Simulation.h Case.h
	g++ -c main.cpp -o main.o -O4 -pg  --std=c++11

Bacterie.o : Bacterie.h Bacterie.cpp
	g++ -c Bacterie.cpp -o Bacterie.o -O4 -pg --std=c++11

Environnement.o : Environnement.h Environnement.cpp Case.h
	g++ -c Environnement.cpp -o Environnement.o -O4 -pg --std=c++11
	
Simulation.o : Simulation.h Simulation.cpp Environnement.h
	g++ -c Simulation.cpp -o Simulation.o -O4 -pg --std=c++11
	
Case.o : Case.h Case.cpp Bacterie.h
	g++ -c Case.cpp -o Case.o -O4 -pg --std=c++11

clean :
	rm -f *.o main

