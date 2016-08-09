#include "PathFinder.h"



PathFinder::PathFinder()
{
}


PathFinder::~PathFinder()
{
}

void PathFinder::clearData()
{
}

std::list<Node*> PathFinder::FindAStar(Node * startNode, Node * endNode, std::vector<Node*> m_nodes)
{
	std::list<Node*> openList;
	std::list<Node*> closedList;
	std::list<Node*> outList;

	for (Node* node : m_nodes)
	{
		node->SetGScore(std::numeric_limits<float>::max());
		node->SetHScore(0);
		node->SetFScore(0);
		node->parent = nullptr;
	}


	Node* currentNode;// = new Node();
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
		//openList.pop_front();
		closedList.push_back(currentNode);	

		for (Edge connections : currentNode->GetConnections())
		{
			//float gScore = currentNode->GetGScore() + connections.GetCost();
			
			bool traversed = false;
			for (Node * node : closedList)
			{
				if (node == connections.GetConnectionNode())
				{
					traversed = true;
					break;
				}
			}
			if (!traversed)
			{
				openList.push_back(connections.GetConnectionNode());
			}

			Node * n = connections.GetConnectionNode();
			float newGscore = currentNode->GetGScore() + connections.GetCost();
			float newHscore = n->GetPos().Distance(endNode->GetPos());
			float newFscore = newGscore + newHscore;

			if (newFscore < n->GetFScore() || n->GetParent() == nullptr)
			{
				n->SetGScore(newGscore);
				n->SetHScore(newHscore);
				n->SetFScore(newFscore);
				n->parent = currentNode;
			}
		}
	}

	currentNode = endNode;
	while (currentNode != nullptr)
	{
		outList.push_back(currentNode);
		currentNode = currentNode->parent;
		if (currentNode == startNode)
			break;
	}
	outList.reverse();
	return outList;
}
