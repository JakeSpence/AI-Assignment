#pragma once
#include "Node.h"
#include <list>
#include <iterator>
#include "Graph.h"

class PathFinder : public Graph
{
protected:
	Graph* m_graph;
public:
	PathFinder();
	virtual ~PathFinder();

	void clearData();
	std::list<Node*> FindAStar(Node * startNode, Node * endNode, std::vector<Node*> m_nodes);
};
