#pragma once
#include "Composite.h"
class NextNode :	public Composite
{
public:
	NextNode();
	NextNode(std::vector<Node*> n);
	~NextNode();

	BehaviourResult Execute(Agent* agent, float deltaTime);

	PathFinder p;
	std::vector<Node*> m_nodes;
};

