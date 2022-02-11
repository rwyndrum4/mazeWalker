#ifndef MAZEWALKER_H
#define MAZEWALKER_H
#include <string>
using namespace std;

class MazeWalker
{
  public:
    int cost = 1;
  /**
  * @pre: call mazewalker calss
  * @post: create mazewalker object
  * @return: none
  * @throw: none
  **/
  MazeWalker(std::string filename);
  ~MazeWalker();
  /**
  * @pre: rows and cols not < 1, file is open, not starting on wall
  * @post: calls walkmaze function
  * @return: none
  * @throw: if starting position is a wall
  **/
  void solveMaze();
  /**
  * @pre: rows and cols not < 1, file is open, not starting on wall
  * @post: prints either the maze, or that there is no solution
  * @return: none
  * @throw: if starting position is a wall
  **/
  void printSolution();
  bool isFileOpen;
  char** m_walkerMaze;
  int m_walkerRows;
  int m_walkerCols;
  int m_walkerRowStart;
  int m_walkerColStart;
  int m_currentStep;
  int** m_visited;
  int** m_ordervisited;
  int** m_queue;
  int m_escaped;
  int waytosolve;//1 for original 2 for breadth first
  int queuesize;
  /**
  * @pre: none
  * @post: either calls itself, or finds an exit
  * @return: true if can move, false if no remaining options to move
  * @throw: none
  **/
  bool walkMaze(int row, int col, int solvetype);
  /**
  * @pre: none
  * @post: marks current location onto m_visited
  * @return: none
  * @throw: none
  **/
  void mark(int row, int col);
  /**
  * @pre: none
  * @post: removes mark from m_visited at current location
  * @return: none
  * @throw: none
  **/
  void unmark(int row, int col);
  /**
  * @pre: next row and col cant be greater than maze or less than 0, also cant move to wall or already traveled location
  * @post: tells whether or not valid
  * @return: true if valid false if not
  * @throw: none
  **/
  bool isValidMove(int nextRow, int nextCol);
  /**
  * @pre: none
  * @post: tells whether at exit or not
  * @return: true if at exit, false if not
  * @throw: none
  **/
  bool isExit(int nextRow, int nextCol);
};

#endif
