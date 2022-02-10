#ifndef MAZEWALKER_H
#define MAZEWALKER_H
#include <string>

class mazeWalker
{
public:
  mazeWalker(std::string fileName);
  ~mazeWalker();
  void walkMaze(); //non-recursive
  void printSolution();

private:
  char** m_maze;
  int m_rows;
  int m_cols;
  int** m_visited;
  int m_stepCount;

  bool walkMaze(int row, int col);  //recursive
  bool mark(int row, int col);
  bool isValidMove(int row, int col);
  bool isExit(int row, int col);
  void unmark(int row, int col);
};

#endif
