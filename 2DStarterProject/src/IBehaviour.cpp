#include "IBehaviour.h"


IBehaviour::IBehaviour()
{
}


IBehaviour::~IBehaviour()
{
	if (m_behaviourList.size() != 0)
	{
		for (IBehaviour* iB : m_behaviourList)
		{
			delete iB;
		}

	}
}

void IBehaviour::AddChild(IBehaviour * b)
{
	m_behaviourList.push_back(b);
}