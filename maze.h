#ifndef MAZE_H
#define MAZE_H
#include <string>

class Maze
{
  public:
  Maze();
  ~Maze();
  /**
  * @pre: rows and cols cant be less than 1 and file must be correct
  * @post: takes file input and turns it into 2D array of chars
  * @return: none
  * @throw: if rows or cols less than 1 or if file incorrect
  **/
  void store(std::string filename);
  /**
  * @pre: none
  * @post: get whether file open
  * @return: bool
  * @throw: none
  **/
  bool getIsFileOpen();
  /**
  * @pre: none
  * @post: get rows
  * @return: int
  * @throw: none
  **/
  int getRows();
  /**
  * @pre: none
  * @post: get cols
  * @return: int
  * @throw: none
  **/
  int getCols();
  /**
  * @pre: none
  * @post: get start row
  * @return: int
  * @throw: none
  **/
  int getRowStart();
  /**
  * @pre: none
  * @post: get start col
  * @return: int
  * @throw: none
  **/
  int getColStart();
  /**
  * @pre: none
  * @post: get maze 2D array
  * @return: char**
  * @throw: none
  **/
  char** getMaze();

  private:
  bool fileIsOpen;
  char** m_maze;
  int m_rows;
  int m_cols;
  int m_rowStart;
  int m_colStart;
};

#endif
