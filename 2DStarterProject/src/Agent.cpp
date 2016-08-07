#include "Agent.h"
#include "PathFinder.h"

Agent::Agent()
{
	m_texture = new Texture("./bin/textures/crate.png");
	m_position.SetX(200);
	m_position.SetY(200);
	m_velocity = Vector2(100, 100);
	m_acceleration = Vector2(0,0);
	m_force = Vector2(0, 0);
	m_maxVelocity = Vector2(30, 30);
	Node n(Vector2(400, 250));
	m_finalTarget = new Node(n);
	m_nearbyNode = new Node(n);
	m_currentTarget = new Node(n);
}

Agent::~Agent()
{
	delete m_texture;
	delete m_target;
	delete m_finalTarget;
	delete m_nearbyNode;
	
	while (true)
	{
		delete m_behaviourTree;
		for (IBehaviour* b : m_behaviourTree->m_behaviourList)
		{
			delete b;
		}
	}
}

void Agent::Update(float deltaTime)
{
	//m_velocity += (m_force * deltaTime);
	//m_position += (m_velocity * deltaTime);
	if (m_currentTarget == nullptr)
	{
		m_currentTarget == m_finalTarget;
	}
	IBehaviour* b = m_behaviourList.front();
	b->Execute(this, deltaTime);
	/*if (m_target == nullptr)
	{
		m_target = m_nearbyNode;
	}
	Vector2 v = m_position - m_target->GetPos();
	v.Normalise();
	v = v * m_maxVelocity;
	m_force = v - m_velocity;

	m_velocity += (m_force * deltaTime);
	m_position += (m_velocity * deltaTime);*/
	//heading = normailise(m_velocity);
}

void Agent::Addforce(Vector2 force)
{
	m_force += force;
}

void Agent::AddBehaviour(IBehaviour* behaviour)
{
	m_behaviourList.push_back(behaviour);
}

void Agent::Draw(SpriteBatch* pass)
{
	pass->drawSprite(m_texture, m_position.GetX(), m_position.GetY(), 50, 50);
}

Vector2 Agent::GetPosition()
{
	return m_position;
}

void Agent::SetPosition(Vector2 v)
{
	m_position = v;
}

void Agent::SetTarget(Node * n)
{
	m_target = n;
}

Node * Agent::GetTarget()
{
	return m_target;
}

void Agent::NextNode()
{
	if (m_target != nullptr || m_position.Distance(m_target->GetPos()) < 50)
	{
		if (m_target->GetParent() != nullptr)
		{
			m_target = m_target->GetParent();
		}
		else
		{
			m_target = m_nearbyNode;
		}
	}
}

void Agent::PathFind(Node * s, Node * e)
{
	PathFinder p;
	p.FindAStar(s, e);
}
