#include "Graph.h"

Graph::Graph()
{
}


Graph::~Graph()
{
	for (Node *n : m_nodes)
	{
		delete n;
	}
}

Node* Graph::AddNode(float x, float y)
{
	m_nodes.push_back(new Node(Vector2(x, y)));
	return m_nodes.back();
}

void Graph::AddConnections(Node * n1, Node * n2)
{
	float weight = sqrt(pow(n2->GetPos().GetX() - n1->GetPos().GetX(), 2) + pow(n2->GetPos().GetY() - n1->GetPos().GetY(), 2));
	n1->AddConnections(n2, weight);
	n2->AddConnections(n1, weight);
}

Node* Graph::FindNodesInRange(float x, float y, float radius)
{
	for (auto& node : m_nodes)
	{
		if (node->GetPos().Distance(Vector2(x, y)) < radius)
		{
			return node;
		}
	}
	return nullptr;
}

Node * Graph::FindNodesInRange(Vector2 v, float radius)
{
	for (auto& node : m_nodes)
	{
		float dis = node->GetPos().Distance(v);
		if (dis < radius)
		{
			return node;
		}
	}
	return nullptr;
}

std::vector<Node *> Graph::GetNodeList()
{
	return m_nodes;
}
