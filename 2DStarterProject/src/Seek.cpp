#include "Seek.h"
#include "PathFinder.h"

Seek::Seek()
{
}


Seek::~Seek()
{
}

BehaviourResult Seek::Execute(Agent * agent, float deltaTime)
{
	Vector2 prevPos = agent->GetPosition();
	Vector2 v = agent->m_currentTarget->GetPos() - agent->GetPosition();
	v.Normalise();
	v = v * agent->m_maxVelocity;
	agent->m_force = v - agent->m_velocity;

	agent->m_velocity += (agent->m_force * deltaTime);
	agent->SetPosition(agent->GetPosition() + (agent->m_velocity * deltaTime));

	if (prevPos != agent->GetPosition())
	{
		return Success;
	}

	return Failure;
}
