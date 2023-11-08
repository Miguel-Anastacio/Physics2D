#include "Application.h"

Application::Application()
    : m_Window( 
        sf::VideoMode(1200, 780),
        "WINDOW_NAME",
        sf::Style::Default,
        sf::ContextSettings(0, 0, 8)
    )
{
    //InitGLFW();
    //// Initialize GLEW (must be done after an OpenGL context is created)
    //glewInit();
    m_EnityManager = new EntityManager(1200, 780);
    
}

Application::~Application()
{
    delete m_EnityManager;
   /* glfwDestroyWindow(Window);
    glfwTerminate();*/
}

//bool Application::InitGLFW()
//{
//    //glfwSetErrorCallback(glfw_error_callback);
//    if (!glfwInit())
//        return false;
//
//    glsl_version = "#version 130";
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
//
//    // Create window with graphics context
//    Window = glfwCreateWindow(1400, 880, "Demo Window", nullptr, nullptr);
//    if (Window == nullptr)
//        return false;
//    glfwMakeContextCurrent(Window);
//    glfwSwapInterval(1);
//
//    // set drop call back
//    // used for detecting filedrop
//    //glfwSetDropCallback(Window, Callback::DragAndDropCallback);
//
//    return true;
//}

void Application::Run()
{
    /*while (!glfwWindowShouldClose(Window))
    {
        glfwPollEvents();


        glfwSwapBuffers(Window);
    }*/
   
    sf::Clock clock;

    m_World.SetCollisionBodiesReference(m_EnityManager->GetBodies());

    while (m_Window.isOpen())
    {
        sf::Time deltaTime = clock.restart();
        sf::Event event;
        while (m_Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_Window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                auto positionInt = sf::Mouse::getPosition(m_Window);
                auto positionFloat = m_Window.mapPixelToCoords(positionInt);
                //auto physicsPos = SfmlPosToSpe(positionFloat);
                Entity ent(positionFloat, Physics2D::Vector2(0, 300 * m_EnityManager->GetEntities().size()));
                if(m_EnityManager->GetEntities().size() < 10)
                    m_EnityManager->AddEntity(ent);
            }
        }

        m_World.Step(deltaTime.asSeconds());
        m_EnityManager->UpdateEntities(deltaTime.asSeconds());
        m_Window.clear();

        for (const auto& ent : m_EnityManager->GetEntities())
        {
            m_Window.draw(ent);
        }

        m_Window.display();
    }
}
