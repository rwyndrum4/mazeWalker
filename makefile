lab7: main.o Executive.o maze.o mazeWalker.o
	g++ -std=c++11 -g -Wall main.o Executive.o maze.o mazeWalker.o -o lab7

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.cpp maze.h mazeWalker.h
	g++ -std=c++11 -g -Wall -c Executive.cpp

maze.o: maze.cpp
	g++ -std=c++11 -g -Wall -c maze.cpp

mazeWalker.o: mazeWalker.cpp
	g++ -std=c++11 -g -Wall -c mazeWalker.cpp

clean:
	rm *.o lab7
