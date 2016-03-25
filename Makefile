all : main

main : main.o Bacterie.o Environnement.o Simulation.o Case.o
	g++ main.o Bacterie.o Environnement.o Simulation.o Case.o -o main

main.o : main.cpp Bacterie.h Environnement.h Simulation.h Case.h
	g++ -c main.cpp -o main.o -g -pg  --std=c++11

Bacterie.o : Bacterie.h Bacterie.cpp
	g++ -c Bacterie.cpp -o Bacterie.o -g -pg --std=c++11

Environnement.o : Environnement.h Environnement.cpp
	g++ -c Environnement.cpp -o Environnement.o -g -pg --std=c++11
	
Simulation.o : Simulation.h Simulation.cpp
	g++ -c Simulation.cpp -o Simulation.o -g -pg --std=c++11
	
Case.o : Case.h Case.cpp
	g++ -c Case.cpp -o Case.o -g -pg --std=c++11

clean :
	rm -f *.o main

