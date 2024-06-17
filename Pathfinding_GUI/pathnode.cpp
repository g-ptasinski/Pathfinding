#include "pathnode.h"

pathnode::pathnode( int ID  ) : m_nodeID(ID)
{
    m_visited   =  0;
    //m_nodeType  = NODE;
}

int pathnode::getNodeID()
{
  return m_nodeID;
}

void pathnode::setVisited()
{
  m_visited = true;
}
