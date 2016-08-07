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
	void SetTarget(Node* n);
	Node* GetTarget();
	void NextNode();
	void PathFind(Node* s, Node* e);

	Node* m_finalTarget;
	Node* m_currentTarget;
	Node* m_nearbyNode = nullptr;
	time_t timer = -1;
	std::list<Node *> m_path;
	Vector2 m_velocity;
	Vector2 m_acceleration;
	Vector2 m_force;
	Vector2 m_maxVelocity;

private:
	Vector2 m_position;
	
	Texture* m_texture;

	Node* m_target;

	std::list<IBehaviour *> m_behaviourList;
	IBehaviour* m_behaviourTree;
};

