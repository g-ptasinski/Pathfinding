#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <memory>
#include <vector>
#include<graphicalnode.h>

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

    std::vector<std::unique_ptr<GraphicalNode>> m_NodeList;
};

#endif // GRID_H
