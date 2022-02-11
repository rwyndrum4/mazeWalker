#include "MazeWalker.h"
#include "Maze.h"
#include "Executive.h"
#include <string>
#include <iostream>
using namespace std;

Executive::Executive()
{
  //
}

Executive::~Executive()
{
  //
}

void Executive::run(std::string filename)
{
  MazeWalker myWalker(filename);
  myWalker.solveMaze();
  myWalker.printSolution();
}
