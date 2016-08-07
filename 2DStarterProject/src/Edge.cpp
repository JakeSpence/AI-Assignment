#include "Edge.h"



Edge::Edge()
{
	connection = nullptr;
	cost = 0;
}

Edge::Edge(Node * node)
{
	connection = node;
	cost = 0;
}

Edge::Edge(Node * node, float a_cost)
{
	connection = node;
	cost = a_cost;
}

Edge::~Edge()
{
}

void Edge::SetCost(float c)
{
	cost = c;
}

float Edge::GetCost()
{
	return cost;
}

void Edge::SetConnectionNode(Node * n)
{
	connection = n;
}

Node * Edge::GetConnectionNode()
{
	return connection;
}
