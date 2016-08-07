#pragma once
#include "Edge.h"
#include "Vector2.h"

#include <vector>

class Node
{
public:
	Node();
	Node(Vector2 a_pos);
	Node(Node * n);
	~Node();

	void AddConnections(Node *n, float weight);

	void SetPos(Vector2 v);
	Vector2 GetPos();
	void SetGScore(float f);
	float GetGScore();
	void SetHScore(float f);
	float GetHScore();
	void SetFScore(float f);
	float GetFScore();
	std::vector<Edge> GetConnections();
	Node* GetParent();
	//void SetParent(Node * n);
	Node *parent = nullptr;

protected:
	Vector2 pos;
	float gScore;
	float hScore;
	float fScore;
	std::vector<Edge> connections;
	
	bool visited = false;
	Node *pNode;

	int degreesOfSeporation;
};

