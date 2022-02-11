#include "MazeWalker.h"
#include <iomanip>
#include "Maze.h"
#include <string>
#include <iostream>
using namespace std;

MazeWalker::MazeWalker(std::string filename)
{
  Maze myMaze;
  myMaze.store(filename);
  isFileOpen = myMaze.getIsFileOpen();
  m_walkerMaze = myMaze.getMaze();
  m_walkerRows = myMaze.getRows();
  m_walkerCols = myMaze.getCols();
  m_walkerRowStart = myMaze.getRowStart();
  m_walkerColStart = myMaze.getColStart();
  m_currentStep = 1;
  if(m_walkerRows < 1)
  {

  }
  else if(m_walkerCols < 1)
  {

  }
  else
  {
    /////////////////////////create the arrays///////////////////////////////////
    //create 2D of correct size for m_visited
    m_visited = new int*[m_walkerRows];
    for(int i = 0; i < m_walkerRows; i++)
    {
      m_visited[i] = new int[m_walkerCols];
    }
    //create 2D of correct size for m_ordervisited
    m_ordervisited = new int*[m_walkerRows];
    for(int i = 0; i < m_walkerRows; i++)
    {
      m_ordervisited[i] = new int[m_walkerCols];
    }
    //create 2D of correct size for m_queue
    m_queue = new int*[m_walkerRows];
    for(int i = 0; i < m_walkerRows; i++)
    {
      m_queue[i] = new int[m_walkerCols];
    }

//////////////////////////initialize the arrays//////////////////////////////////////

    //assign all values of m_visited to 0
    for(int i = 0; i < m_walkerRows; i++)
    {
      for(int j = 0; j < m_walkerCols; j++)
      {
        m_visited[i][j] = 0;
      }
    }
    //assign all values of m_ordervisited to 0
    for(int i = 0; i < m_walkerRows; i++)
    {
      for(int j = 0; j < m_walkerCols; j++)
      {
        m_ordervisited[i][j] = 0;
      }
    }
    //assign all values of m_queue to 0
    for(int i = 0; i < m_walkerRows; i++)
    {
      for(int j = 0; j < m_walkerCols; j++)
      {
        m_queue[i][j] = 0;
      }
    }
    queuesize = 1;

  }
}

MazeWalker::~MazeWalker()
{
  if(m_walkerRows < 1)
  {

  }
  else if(m_walkerCols < 1)
  {

  }
  else if(isFileOpen == false)
  {

  }
  else
  {
    for(int i = 0; i < m_walkerRows; i++)
    {
      delete m_walkerMaze[i];
      delete m_visited[i];
      delete m_queue[i];
    }
    delete m_walkerMaze;
    delete m_visited;
    delete m_queue;
  }
}

void MazeWalker::solveMaze()
{
  if(m_walkerRows < 1)
  {

  }
  else if(m_walkerCols < 1)
  {

  }
  else if(isFileOpen == false)
  {

  }
  else if(m_walkerMaze[m_walkerRowStart][m_walkerColStart] == 'W')
  {
    cout << "Starting position is in a wall.\n";
  }
  else
  {
    walkMaze(m_walkerRowStart, m_walkerColStart, 1);
  }
}

void MazeWalker::printSolution()
{
  if(m_walkerRows < 1)
  {

  }
  else if(m_walkerCols < 1)
  {

  }
  else if(isFileOpen == false)
  {

  }
  else if(m_walkerMaze[m_walkerRowStart][m_walkerColStart] == 'W')
  {
    cout << "Starting position is in a wall.\n";
  }
  else
  {
    if(m_escaped == 1)
    {
      cout << "Starting position: " << m_walkerRowStart << ", " << m_walkerColStart << '\n';
      cout << "Size: " << m_walkerRows << ", " << m_walkerCols << '\n';
      for(int i = 0; i < m_walkerRows; i++)
      {
        for(int j = 0; j < m_walkerCols; j++)
        {
          cout << setw(3) << m_visited[i][j];
        }
        cout << '\n';
      }
      cout << "\n\nOrder visited: \n";
      for(int i = 0; i < m_walkerRows; i++)
      {
        for(int j = 0; j < m_walkerCols; j++)
        {
          cout << setw(3) << m_ordervisited[i][j];
        }
        cout << '\n';
      }
      //queue
      cout << "\n\nQueue:\n";
      for(int i = 0; i < m_walkerRows; i++)
      {
        for(int j = 0; j < m_walkerCols; j++)
        {
          cout << setw(3) << m_queue[i][j];
        }
        cout << '\n';
      }
      cout << "We escaped!\n";
    }
    else
    {
      cout << "Starting position: " << m_walkerRowStart << ", " << m_walkerColStart << '\n';
      cout << "Size: " << m_walkerRows << ", " << m_walkerCols << '\n';
      cout << "No way out!\n";
    }
  }
}

bool MazeWalker::walkMaze(int row, int col, int solvetype)
{
  mark(row, col);
  //if im at the exit
  if( isExit(row, col) ){
    m_escaped = 1;
    return(true);
  }
  if(solvetype == 1){
    //UP
    if( isValidMove(row-1, col) ){
      if( walkMaze(row-1, col, 1) ){
        return(true);
      }
    }

    //RIGHT
    if( isValidMove(row, col+1) ){
      if( walkMaze(row, col+1, 1) ){
        return(true);
      }
    }

    //DOWN
    if( isValidMove(row+1, col) ){
      if( walkMaze(row+1, col, 1) ){
        return(true);
      }
    }

    //LEFT
    if( isValidMove(row, col-1) ){
      if( walkMaze(row, col-1, 1) ){
        return(true);
      }
    }
    //This does not lead to an exit
    unmark(row, col);
    return(false);
  }
  else if(solvetype == 2){

  }

}

void MazeWalker::mark(int row, int col)
{
  m_visited[row][col] = m_currentStep;
  m_ordervisited[row][col] = cost;
//queue each surrounding tile
  if(isValidMove(row-1, col) == true){
    m_queue[row-1][col] = queuesize;
  }
  if(isValidMove(row, col+1) == true){
    m_queue[row][col+1] = queuesize;
  }
  if(isValidMove(row+1, col) == true){
    m_queue[row+1][col] = queuesize;
  }
  if(isValidMove(row, col-1) == true){
    m_queue[row][col-1] = queuesize;
  }
  queuesize++;
  m_currentStep++;
  cost++;
}

void MazeWalker::unmark(int row, int col)
{
  m_visited[row][col] = 0;
  m_currentStep--;
}

bool MazeWalker::isValidMove(int nextRow, int nextCol)
{
  if(nextRow >= m_walkerRows)
  {
    return(false);
  }
  else if(nextCol >= m_walkerCols)
  {
    return(false);
  }
  else if(nextRow < 0)
  {
    return(false);
  }
  else if(nextCol < 0)
  {
    return(false);
  }
  else if(m_walkerMaze[nextRow][nextCol] == 'W')
  {
    return(false);
  }
  else if(m_visited[nextRow][nextCol] > 0)
  {
    return(false);
  }
  else
  {
    return(true);
  }
}

bool MazeWalker::isExit(int nextRow, int nextCol)
{
  if(m_walkerMaze[nextRow][nextCol] == 'E')
  {
    return(true);
  }
  else
  {
    return(false);
  }
}
