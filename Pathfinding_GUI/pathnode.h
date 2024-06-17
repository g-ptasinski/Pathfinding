#ifndef PATHNODE_H
#define PATHNODE_H
/*
enum NodeTypes
{
    NODE = 0,
    START,
    FINISH
};
*/
class pathnode
{
  public:

    pathnode( int ID );
    ~pathnode(){};

    int getNodeID();
    void setVisited();


  private:

    const int m_nodeID;
    bool  m_visited;
    int     m_nodeType;

};

#endif // PATHNODE_H
