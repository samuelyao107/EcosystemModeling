main : main.cpp Aquarium.o Bestiole.o Milieu.o Gregaire.o Peureuse.o Kamikaze.o Prevoyant.o
	g++ -Wall -std=c++14 -o main main.cpp Aquarium.o Bestiole.o Milieu.o Gregaire.o Peureuse.o Kamikaze.o Prevoyant.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++14  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++14  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++14  -c Milieu.cpp -I .

Gregaire.o : Gregaire.h Gregaire.cpp
	g++ -Wall -std=c++14 -c Gregaire.cpp -I .

Peureuse.o : Peureuse.h Peureuse.cpp
	g++ -Wall -std=c++14 -c Peureuse.cpp -I .	

Kamikaze.o : Kamikaze.h Kamikaze.cpp
	g++ -Wall -std=c++14 -c Kamikaze.cpp -I .	

Prevoyant.o : Prevoyant.h Prevoyant.cpp		
	g++ -Wall -std=c++14 -c Prevoyant.cpp -I .
clean:
	rm -rf *.o main

