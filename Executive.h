#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <string>

class Executive
{
  public:
  Executive();
  ~Executive();
  /**
  * @pre: none
  * @post: creates mazewalker object, calls to solve maze and print solution
  * @return: none
  * @throw: none
  **/
  void run(std::string filname);
};

#endif
