#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <memory>
#include <vector>
#include<pathnode.h>

class grid
{
  public:
    grid(int X, int Y);
    ~grid(){};

    void getNodes();
    int getWidth();
    int getHeight();

  private:

    int m_width;
    int m_height;

    std::vector<std::unique_ptr<pathnode>> m_NodeList;
};

#endif // GRID_H
