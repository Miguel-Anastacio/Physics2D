#pragma once
//#include "glew.h"
//#include "GLFW/glfw3.h"
#include <SFML/Graphics.hpp>
#include <PhysicsWorld.h>
#include "EntityManager.h"
#include "Debug/EngineDataUI.h"

class Application
{
public:
	Application();
	~Application();
	//bool InitGLFW();
	void Run();
	void RenderDebugInfo(float dt, int collisionsBP, int collisions);
	
private:

private:
	//GLFWwindow* Window;
	//const char* glsl_version;
	sf::RenderWindow m_Window;
	Physics2D::PhysicsWorld m_World;
	EntityManager* m_EnityManager;

	sf::Font m_Font;
	sf::Text m_Fps;
	sf::Text m_FpsCount;
	sf::Text m_Objects;
	sf::Text m_ObjectsCount;
	sf::Text m_CollisionsCount;
	sf::Text m_CollisionsBPCount;

	std::unique_ptr<EngineDataUI> m_EngineData;
	

};

