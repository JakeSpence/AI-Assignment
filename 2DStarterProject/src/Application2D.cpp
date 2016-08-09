#include "Application2D.h"
#include <GLFW/glfw3.h>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Node.h"
#include "PathFinder.h"
#include "IBehaviour.h"
#include "NextNode.h"
#include "Selector.h"
#include "Sequence.h"
#include "TimerCount.h"
#include "TimerReset.h"
#include "DetectEnemy.h"
#include "Seek.h"
#include "Flee.h"
#include "Distance.h"
#include "RandomPath.h"

Application2D::Application2D() 
{
}

Application2D::~Application2D()
{
	
}

bool Application2D::startup() 
{
	createWindow("A.I. Project", 1280, 720);

	m_spriteBatch = new SpriteBatch();

	m_nodeTexture = new Texture("./bin/textures/nodeTexture.png");

	m_font = new Font("./bin/font/consolas.ttf", 32);

	m_agentGuard = new Agent();
	m_agentEscapee = new Agent();

	m_graph = new Graph();

	float graphScale = 2.5f;

	/*int countW = 50;
	int countH = 50;
	Node* previous = nullptr;
	Node* below = nullptr;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			Node* current = m_graph->AddNode(countH * graphScale, countW * graphScale);
			if (previous != nullptr)
			{
				m_graph->AddConnections(previous, current);
			}
			if(i > 0)
			{
				below = m_graph->GetNodeList().begin() + j;
				m_graph->AddConnections(current, below);
			}
			previous = current;
			countH += 50;
		}
		countH = 50;
		countW += 50;
		previous = nullptr;
	}*/

	Node *b = m_graph->AddNode(100 * graphScale, 100 * graphScale);
	Node *c = m_graph->AddNode(150 * graphScale, 100 * graphScale);
	Node *d = m_graph->AddNode(200 * graphScale, 100 * graphScale);
	Node *e = m_graph->AddNode(250 * graphScale, 100 * graphScale);
	Node *f = m_graph->AddNode(300 * graphScale, 100 * graphScale);
	Node *g = m_graph->AddNode(350 * graphScale, 100 * graphScale);
	Node *h = m_graph->AddNode(400 * graphScale, 100 * graphScale);

	Node *i = m_graph->AddNode(100 * graphScale, 150 * graphScale);
	Node *j = m_graph->AddNode(150 * graphScale, 150 * graphScale);
	Node *k = m_graph->AddNode(200 * graphScale, 150 * graphScale);
	Node *l = m_graph->AddNode(250 * graphScale, 150 * graphScale);
	Node *m = m_graph->AddNode(300 * graphScale, 150 * graphScale);
	Node *n = m_graph->AddNode(350 * graphScale, 150 * graphScale);
	Node *o = m_graph->AddNode(400 * graphScale, 150 * graphScale);

	Node *p = m_graph->AddNode(100 * graphScale, 200 * graphScale);
	Node *q = m_graph->AddNode(150 * graphScale, 200 * graphScale);
	Node *r = m_graph->AddNode(200 * graphScale, 200 * graphScale);
	Node *s = m_graph->AddNode(250 * graphScale, 200 * graphScale);
	Node *t = m_graph->AddNode(300 * graphScale, 200 * graphScale);
	Node *u = m_graph->AddNode(350 * graphScale, 200 * graphScale);
	Node *v = m_graph->AddNode(400 * graphScale, 200 * graphScale);

	Node *w = m_graph->AddNode(100 * graphScale, 250 * graphScale);
	Node *x = m_graph->AddNode(150 * graphScale, 250 * graphScale);
	Node *y = m_graph->AddNode(200 * graphScale, 250 * graphScale);
	Node *z = m_graph->AddNode(250 * graphScale, 250 * graphScale);
	Node *aa = m_graph->AddNode(300 * graphScale, 250 * graphScale);
	Node *ab = m_graph->AddNode(350 * graphScale, 250 * graphScale);
	Node *ac = m_graph->AddNode(400 * graphScale, 250 * graphScale);

	m_graph->AddConnections(b, c);
	m_graph->AddConnections(c, d);
	m_graph->AddConnections(d, e);
	m_graph->AddConnections(e, f);
	m_graph->AddConnections(f, g);
	m_graph->AddConnections(g, h);

	m_graph->AddConnections(i, j);
	m_graph->AddConnections(j, k);
	m_graph->AddConnections(k, l);
	m_graph->AddConnections(l, m);
	m_graph->AddConnections(m, n);
	m_graph->AddConnections(n, o);

	m_graph->AddConnections(p, q);
	m_graph->AddConnections(q, r);
	m_graph->AddConnections(r, s);
	m_graph->AddConnections(s, t);
	m_graph->AddConnections(t, u);
	m_graph->AddConnections(u, v);

	m_graph->AddConnections(w, x);
	m_graph->AddConnections(x, y);
	m_graph->AddConnections(y, z);
	m_graph->AddConnections(z, aa);
	m_graph->AddConnections(aa, ab);
	m_graph->AddConnections(ab, ac);

	m_graph->AddConnections(b, i);
	m_graph->AddConnections(c, j);
	m_graph->AddConnections(d, k);
	m_graph->AddConnections(e, l);
	m_graph->AddConnections(f, m);
	m_graph->AddConnections(g, n);
	m_graph->AddConnections(h, o);

	m_graph->AddConnections(i, p);
	m_graph->AddConnections(j, q);
	m_graph->AddConnections(k, r);
	m_graph->AddConnections(l, s);
	m_graph->AddConnections(m, t);
	m_graph->AddConnections(n, u);
	m_graph->AddConnections(o, v);

	m_graph->AddConnections(p, w);
	m_graph->AddConnections(q, x);
	m_graph->AddConnections(r, y);
	m_graph->AddConnections(s, z);
	m_graph->AddConnections(t, aa);
	m_graph->AddConnections(u, ab);
	m_graph->AddConnections(v, ac);

	m_agentGuard->SetPosition(Vector2(200 * graphScale, 200 * graphScale));
	m_agentEscapee->SetPosition(Vector2(100 * graphScale, 100 * graphScale));

	m_agentGuard->m_nearbyNode = m_graph->FindNodesInRange(m_agentGuard->GetPosition(), 200);
	m_agentEscapee->m_nearbyNode = m_graph->FindNodesInRange(m_agentEscapee->GetPosition(), 200);

	m_agentEscapee->m_finalTarget.push_back(m_graph->FindNodesInRange(400 * graphScale, 250 * graphScale, 10));
	m_agentGuard->m_finalTarget.push_back(m_graph->FindNodesInRange(100 * graphScale, 100 * graphScale, 10));
	m_agentGuard->m_finalTarget.push_back(m_graph->FindNodesInRange(400 * graphScale, 250 * graphScale, 10));
	m_agentGuard->m_finalTarget.push_back(m_graph->FindNodesInRange(400 * graphScale, 100 * graphScale, 10));
	m_agentGuard->m_finalTarget.push_back(m_graph->FindNodesInRange(100 * graphScale, 250 * graphScale, 10));
	

	m_agentEscapee->m_enemy = m_agentGuard;
	m_agentGuard->m_enemy = m_agentEscapee;

	PathFinder path;
	m_agentEscapee->m_path = path.FindAStar(m_agentEscapee->m_nearbyNode, m_agentEscapee->m_finalTarget.front(), m_graph->GetNodeList());
	m_agentGuard->m_path = path.FindAStar(m_agentGuard->m_nearbyNode, m_agentGuard->m_finalTarget.front(), m_graph->GetNodeList());

	m_agentEscapee->m_currentTarget = m_agentEscapee->m_path.front();
	m_agentGuard->m_currentTarget = m_agentGuard->m_path.front();
	
	Selector* rootGuard = new Selector(), *rootEscapee = new Selector(), *lostTarget = new Selector();
	Sequence* chase = new Sequence(), *search = new Sequence(), *travel = new Sequence(), *flee = new Sequence(), *patrol = new Sequence();
	TimerCount* timerCount = new TimerCount();
	TimerReset* timerReset = new TimerReset();
	NextNode* nextN = new NextNode(m_graph->GetNodeList());
	DetectEnemy* detectE = new DetectEnemy();
	Seek* seek = new Seek();
	Flee* retreat = new Flee();
	Distance* distance = new Distance();
	RandomPath* randPath = new RandomPath();

	rootGuard->AddChild(chase);
	rootGuard->AddChild(lostTarget);

	chase->AddChild(detectE);
	chase->AddChild(timerReset);
	chase->AddChild(seek);

	lostTarget->AddChild(search);
	lostTarget->AddChild(patrol);

	search->AddChild(timerCount);
	search->AddChild(randPath);

	patrol->AddChild(nextN);
	patrol->AddChild(seek);

	rootEscapee->AddChild(flee);
	rootEscapee->AddChild(travel);

	flee->AddChild(detectE);
	flee->AddChild(retreat);

	travel->AddChild(nextN);
	travel->AddChild(seek);

	m_agentEscapee->AddBehaviour(rootEscapee);
	m_agentGuard->AddBehaviour(rootGuard);

	return true;
}

void Application2D::shutdown() 
{
	delete m_spriteBatch;
	delete m_nodeTexture;
	delete m_font;
	delete m_agentGuard;
	delete m_agentEscapee;
	delete m_graph;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	m_agentGuard->m_nearbyNode = m_graph->FindNodesInRange(m_agentGuard->GetPosition(), 200);
	m_agentEscapee->m_nearbyNode = m_graph->FindNodesInRange(m_agentEscapee->GetPosition(), 200);

	m_agentGuard->Update(deltaTime);
	m_agentEscapee->Update(deltaTime);

	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	m_startNode = m_agentGuard->m_nearbyNode;
	m_endNode = m_agentEscapee->m_nearbyNode;

	m_agentEscapee->Draw(m_spriteBatch);
	m_agentGuard->Draw(m_spriteBatch);

	for (auto& node : m_graph->GetNodeList())
	{
		m_spriteBatch->drawSprite(m_nodeTexture, node->GetPos().GetX(), node->GetPos().GetY(), 30, 30);
		for (auto& edge : node->GetConnections())
		{
			m_spriteBatch->drawLine(node->GetPos().GetX(), node->GetPos().GetY(), edge.GetConnectionNode()->GetPos().GetX(), edge.GetConnectionNode()->GetPos().GetY());
		}
	}
	/*if (m_startNode != nullptr)
	{
		m_spriteBatch->drawSprite(m_nodeTexture, m_startNode->GetPos().GetX(), m_startNode->GetPos().GetY(), 30, 30);
	}
	if (m_endNode != nullptr)
	{
		std::list<Node*> outPath;
		PathFinder find;
		find.FindAStar(m_startNode, m_endNode);
		for (auto& node : outPath)
		{
			m_spriteBatch->drawSprite(m_nodeTexture, node->GetPos().GetX(), node->GetPos().GetY(), 30, 30);
		}
	}*/

	// done drawing sprites
	m_spriteBatch->end();	
}