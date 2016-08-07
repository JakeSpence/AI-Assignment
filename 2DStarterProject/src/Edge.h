#pragma once

class Node;
class Edge
{
public:
	Edge();
	Edge(Node *node);
	Edge(Node *node, float a_cost);
	~Edge();

	void SetCost(float c);
	float GetCost();
	void SetConnectionNode(Node* n);
	Node* GetConnectionNode();

private:
	Node* origin;
	Node* connection;
	float cost;
};

