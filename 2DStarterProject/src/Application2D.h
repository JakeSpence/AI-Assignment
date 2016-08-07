#pragma once
#include "Agent.h"
#include "BaseApplication.h"
#include "Graph.h"

class SpriteBatch;
class Texture;
class Font;

class Application2D : public BaseApplication {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual bool update(float deltaTime);
	virtual void draw();

protected:

	SpriteBatch*	m_spriteBatch;
	Texture*		m_nodeTexture;
	Font*			m_font;
	Agent*			m_agentGuard,* m_agentEscapee;
	Graph*			m_graph;
	Node*			m_startNode = nullptr;
	Node*			m_endNode = nullptr;
};