lab7: main.o Executive.o Maze.o MazeWalker.o
	g++ -std=c++11 -g -Wall main.o Executive.o Maze.o MazeWalker.o -o lab7

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp
	g++ -std=c++11 -g -Wall -c Executive.cpp

Maze.o: Maze.h Maze.cpp
	g++ -std=c++11 -g -Wall -c Maze.cpp

MazeWalker.o: MazeWalker.h MazeWalker.cpp
	g++ -std=c++11 -g -Wall -c MazeWalker.cpp

clean:
	rm *.o lab7
