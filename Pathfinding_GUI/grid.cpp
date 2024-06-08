#include "grid.h"
#include "pathnode.h"

grid::grid(int X, int Y) : m_width(X), m_height(Y)
{
    for(int i = 0; i <  m_width*m_height ; i++)
      {
        m_NodeList.push_back(std::make_unique<pathnode>(i));
      }
}

void grid::getNodes()
{
  for(auto &node : m_NodeList)
    {
      std::cout<<node->getNodeID()<<std::endl;
    }
}
