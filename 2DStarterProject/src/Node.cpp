#include "Node.h"

Node::Node()
{
	pos = Vector2(0, 0);
	gScore = 0;
	parent = nullptr;
	hScore = 0;
	fScore = 0;
	connections;
	visited = false;
	pNode;
}

Node::Node(Vector2 a_pos)
{
	pos = a_pos;
	gScore = 0;
	parent = nullptr;
	hScore = 0;
	fScore = 0;
	connections;
	visited = false;
	pNode;
}

Node::Node(Node * n)
{
	pNode = n;
}

Node::~Node()
{
}

void Node::AddConnections(Node *n, float weight)
{
	connections.push_back(Edge(n, weight));
}

void Node::SetPos(Vector2 v)
{
	pos = v;
}

Vector2 Node::GetPos()
{
	if (pos == nullptr)
	{
		return Vector2(0, 0);
	}
	return pos;
}

void Node::SetGScore(float f)
{
	gScore = f;
}

float Node::GetGScore()
{
	return gScore;
}

void Node::SetHScore(float f)
{
	hScore = f;
}

float Node::GetHScore()
{
	return hScore;
}

void Node::SetFScore(float f)
{
	fScore = f;
}

float Node::GetFScore()
{
	return fScore;
}

std::vector<Edge> Node::GetConnections()
{
	return connections;
}

Node * Node::GetParent()
{
	return parent;
}