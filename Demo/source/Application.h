#pragma once
//#include "glew.h"
//#include "GLFW/glfw3.h"
#include <SFML/Graphics.hpp>
#include <PhysicsWorld.h>
#include "EntityManager.h"

class Application
{
public:
	Application();
	~Application();
	//bool InitGLFW();
	void Run();
	
	
private:

	//GLFWwindow* Window;
	//const char* glsl_version;
	sf::RenderWindow m_Window;
	Physics2D::PhysicsWorld m_World;
	EntityManager* m_EnityManager;


};

