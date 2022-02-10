#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <fstream>
#include <string>
#include "mazeWalker.h"

class Executive
{
private:
  std::string filename;

public:
  Executive(char* input);
  ~Executive();
  void run();

};

#endif
