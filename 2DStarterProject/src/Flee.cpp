#include "Flee.h"

Flee::Flee()
{
}


Flee::~Flee()
{
}

BehaviourResult Flee::Execute(Agent * agent, float deltaTime)
{
	Vector2 prevPos = agent->GetPosition();
	Vector2 v = agent->GetPosition() - agent->m_currentTarget->GetPos();
	v.Normalise();
	v = v * agent->m_maxVelocity;
	agent->m_force = v - agent->m_velocity;

	agent->m_velocity += (agent->m_force * deltaTime);
	agent->GetPosition() += (agent->m_velocity * deltaTime);

	if (prevPos != agent->GetPosition())
	{
		return Success;
	}

	return Failure;
}
