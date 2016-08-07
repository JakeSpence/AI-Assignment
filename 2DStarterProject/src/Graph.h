#pragma once
#include "Edge.h"
#include "Node.h"
#include <list>
#include <algorithm>
#include <vector>
#include "Vector2.h"

class Graph
{
public:
	Graph();
	virtual ~Graph();

	Node* AddNode(float x, float y);
	void AddConnections(Node *n1, Node *n2);
	Node* FindNodesInRange(float x, float y, float radius);
	Node* FindNodesInRange(Vector2 v, float radius);

	std::vector<Node *> GetNodeList();

protected:
	std::vector<Node *> m_nodes;
};

