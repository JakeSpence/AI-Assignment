#include "Agent.h"
#include "PathFinder.h"

Agent::Agent()
{
	m_texture = new Texture("./bin/textures/crate.png");
	m_position.SetX(200);
	m_position.SetY(200);
	m_velocity = Vector2(20, 20);
	m_acceleration = Vector2(10,10);
	m_force = Vector2(0, 0);
	m_maxVelocity = Vector2(100, 100);
	Node n(Vector2(400, 250));
	m_nearbyNode = new Node(n);
	m_currentTarget = new Node(n);
}

Agent::~Agent()
{
	delete m_texture;
	delete m_enemy;
	delete m_nearbyNode;
	delete m_currentTarget;
	
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
	if (m_currentTarget == nullptr)
	{
		m_currentTarget = m_finalTarget.front();
	}

	for (auto b : m_behaviourList)
	{
		b->Execute(this, deltaTime);
	}
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
