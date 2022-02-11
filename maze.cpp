#include "Maze.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Maze::Maze()
{
  //
}

Maze::~Maze()
{
  //
}

void Maze::store(std::string filename)
{
  ifstream inFile;
  inFile.open(filename);
  if(inFile.is_open())
  {
    fileIsOpen = true;
    //take size and start position
    inFile >> m_rows >> m_cols >> m_rowStart >> m_colStart;
    if(m_rows < 1)
    {
      cout << "Invalid number of rows.\n";
    }
    else if(m_cols < 1)
    {
      cout << "Invalid number of columns.\n";
    }
    else
    {
      //create 2D array of the right size
      m_maze = new char*[m_rows];
      for(int i = 0; i < m_rows; i++)
      {
        m_maze[i] = new char[m_cols];
      }
      //fill the 2D array with the chracters of the maze
      std::string currentRow = "John Doe\n";
      for(int i = 0; i < m_rows; i++)
      {
        inFile >> currentRow;
        for(int j = 0; j < m_cols; j++)
        {
          m_maze[i][j] = currentRow.at(j);
        }
      }
    }
  }
  else
  {
    fileIsOpen = false;
    cout << "Could not open file.\n";
  }
}

int Maze::getRowStart()
{
  return(m_rowStart);
}

int Maze::getColStart()
{
  return(m_colStart);
}

char** Maze::getMaze()
{
  return(m_maze);
}

int Maze::getRows()
{
  return(m_rows);
}

int Maze::getCols()
{
  return(m_cols);
}

bool Maze::getIsFileOpen()
{
  return(fileIsOpen);
}
