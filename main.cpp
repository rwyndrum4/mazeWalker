#include "Executive.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  if(argc == 2)
  {
    Executive myExec;
    myExec.run(argv[1]);
  }
  else
  {
    cout << "Incorrect number of parameters.\n";
  }
}
