#include "IBehaviour.h"


IBehaviour::IBehaviour()
{
}


IBehaviour::~IBehaviour()
{
}

void IBehaviour::AddChild(IBehaviour * b)
{
	m_behaviourList.push_back(b);
}