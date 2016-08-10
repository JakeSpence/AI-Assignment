#pragma once
#include "Vector2.h"
#include <list>
#include "SpriteBatch.h"
#include "Texture.h"
#include "Node.h"
#include "IBehaviour.h"

class Agent
{
public:
	Agent();
	~Agent();

	virtual void Update(float deltaTime);

	void Addforce(Vector2 force);
	void AddBehaviour(IBehaviour* behaviour);
	void Draw(SpriteBatch* spriteBatch);

	Vector2 GetPosition();
	void SetPosition(Vector2 v);

	std::list<Node*> m_finalTarget;
	Agent* m_enemy = nullptr;
	Node* m_currentTarget;
	Node* m_nearbyNode = nullptr;
	time_t m_timer = -1;
	std::list<Node *> m_path;
	Vector2 m_velocity;
	Vector2 m_acceleration;
	Vector2 m_force;
	Vector2 m_maxVelocity;
	
	int count = 0;

	std::list<IBehaviour *> m_behaviourList;

private:
	Vector2 m_position;
	
	Texture* m_texture;

	IBehaviour* m_behaviourTree;
};

