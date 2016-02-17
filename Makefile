all : main

main : main.o Bacterie.o Environnement.o Simulation.o
	g++ main.o Bacterie.o Environnement.o Simulation.o -g -o main --std=c++11

main.o : main.cpp Bacterie.h Environnement.h Simulation.h 
	g++ -c main.cpp -o main.o -g --std=c++11

Bacterie.o : Bacterie.h Bacterie.cpp
	g++ -c Bacterie.cpp -o Bacterie.o -g --std=c++11

Environnement.o : Environnement.h Environnement.cpp
	g++ -c Environnement.cpp -o Environnement.o -g --std=c++11
	
Simulation.o : Simulation.h Simulation.cpp
	g++ -c Simulation.cpp -o Simulation.o -g --std=c++11

clean :
	rm -f *.o main

