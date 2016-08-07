#include "PathFinder.h"



PathFinder::PathFinder()
{
}


PathFinder::~PathFinder()
{
}

std::list<Node*> PathFinder::FindAStar(Node * startNode, Node * endNode)
{
	std::list<Node*> openList;
	std::list<Node*> closedList;
	std::list<Node*> outList;

	for (Node* node : m_nodes)
	{
		node->SetGScore(std::numeric_limits<float>::max());
		node->parent = nullptr;
	}


	Node* currentNode = new Node();
	startNode->SetGScore(0);
	openList.push_back(startNode);

	while (!openList.empty())
	{
		openList.sort([](Node * n1, Node * n2)
		{
			return n1->GetFScore() < n2->GetFScore();
		});

		currentNode  = openList.front();

		if (currentNode == endNode)
		{
			break;
		}

		openList.remove(currentNode);
		closedList.push_back(currentNode);	

		for (Edge connections : currentNode->GetConnections())
		{
			float gScore = currentNode->GetGScore() + connections.GetCost();
			
			for (Node * node : closedList)
			{
				if (node == connections.GetConnectionNode())
				{
					openList.push_back(connections.GetConnectionNode());
				}
			}

			if (currentNode->GetGScore() + connections.GetCost() < connections.GetConnectionNode()->GetGScore())
			{
				Node * n = connections.GetConnectionNode();
				n->SetGScore(currentNode->GetGScore() + connections.GetCost());
				n->SetHScore(n->GetPos().Distance(endNode->GetPos()));
				n->SetFScore(n->GetGScore() + n->GetHScore());
				n->parent = currentNode;
			}
		}
	}

	currentNode = endNode;
	while (currentNode != nullptr)
	{
		outList.push_front(currentNode);
		currentNode = currentNode->parent;
	}
	delete currentNode;
	return outList;
}
