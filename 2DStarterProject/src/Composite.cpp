#include "Composite.h"



Composite::Composite()
{
}


Composite::~Composite()
{
	if (m_behaviourList.size() != 0)
	{
		for (IBehaviour* iB : m_behaviourList)
		{
			delete iB;
		}

	}
}
