#pragma once
#include "Node.h"
#include <list>
#include <iterator>
#include "Graph.h"

class PathFinder : public Graph
{
public:
	PathFinder();
	virtual ~PathFinder();
	std::list<Node*> FindAStar(Node * startNode, Node * endNode);
};
