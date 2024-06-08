#include "grid.h"
#include "pathnode.h"

grid::grid(int X, int Y) : m_width(X), m_height(Y)
{
  if(m_width <=0 || m_height<=0 )
    {
      std::cout<<"Dimensions must be positive"<<std::endl;
      std::cout<<"Proceeding with 10x10"<<std::endl;
      m_width = 10;
      m_height = 10;
    }

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

int grid::getWidth()
{
  return m_width;
}

int grid::getHeight()
{
  return m_height;
}
