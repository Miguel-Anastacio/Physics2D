#include "Application.h"
#include "Circle.h"
#include "Aabb.h"

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
    
    if (m_Font.loadFromFile("fonts/Roboto-Bold.ttf"))
    {

        m_Fps.setFont(m_Font);
        m_FpsCount.setFont(m_Font);
        m_Objects.setFont(m_Font);
        m_ObjectsCount.setFont(m_Font);
    }

    m_Fps.setPosition(sf::Vector2f(0, 0));
    m_FpsCount.setPosition(sf::Vector2f(300, 0));
    m_Fps.setFillColor(sf::Color::Green);
    m_FpsCount.setFillColor(sf::Color::Green);
    m_Objects.setPosition(sf::Vector2f(0, 50));
    m_ObjectsCount.setPosition(sf::Vector2f(300, 50));
    m_Objects.setFillColor(sf::Color::Green);
    m_ObjectsCount.setFillColor(sf::Color::Green);

    m_Fps.setString("FPS: ");
    m_Objects.setString("Number of Objects: ");

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

    //m_Window.setFramerateLimit(60.0f);
    sf::Clock clock;
    // Create Some Static Objects
    Aabb Floor(sf::Vector2f(100, 500), Physics2D::Vector2(400, 50));
    Floor.GetRigidbody()->SetIsKinematic(false);
    Floor.GetShape()->setFillColor(sf::Color::Red);
    Floor.GetShape()->setOutlineColor(sf::Color::White);



    //m_World.SetCollisionBodiesReference(m_EnityManager->GetBodies());
    // add floor
    m_EnityManager->AddEntity(Floor);
    //m_EnityManager->m_Entities.push_back(Aabb(sf::Vector2f(100, 500), Physics2D::Vector2(400, 50)));
    m_World.m_CollisionBodies.emplace_back(m_EnityManager->GetEntities().back().GetRigidbody());

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
                //rcle ent(positionFloat, Physics2D::Vector2(0, 300 * m_EnityManager->GetEntities().size()));
                //Circle circle(positionFloat, 50.0f);
                if (m_EnityManager->GetEntities().size() < 1000)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        /* m_EnityManager->AddEntity(Circle(positionFloat, 50.0f));
                         m_World.m_CollisionBodiesVector.emplace_back(m_EnityManager->GetEntities().back().GetRigidbody());*/

                        for (int i = 0; i < 100; i++)
                        {                        
                            m_EnityManager->AddEntity(Circle(positionFloat, 10.0f));
                            m_World.m_CollisionBodies.emplace_back(m_EnityManager->GetEntities().back().GetRigidbody());
                            positionFloat.x +=  20;
                        }
                    }
                    if (event.mouseButton.button == sf::Mouse::Right)
                    {
                         m_EnityManager->AddEntity(Aabb(positionFloat, Physics2D::Vector2(25, 25)));
                         m_World.m_CollisionBodies.emplace_back(m_EnityManager->GetEntities().back().GetRigidbody());

                    }
                }
                    //m_EnityManager
            }
        }

        m_World.Step(deltaTime.asSeconds());
        m_EnityManager->UpdateEntities(deltaTime.asSeconds());

        // this cleanup should be more efficient
        // look into how to improve
        m_World.CleanupCollisionBodies(m_EnityManager->CleanupEntities());

        m_Window.clear();

        for (const auto& ent : m_EnityManager->GetEntities())
        {
            m_Window.draw(ent);
        }

        RenderDebugInfo(deltaTime.asSeconds());

        m_Window.display();
    }
}

void Application::RenderDebugInfo(const float& dt)
{
    float fps = 1 / dt;
    //m_FpsCount.setString(sf::String(std::to_string(fps)));
    m_ObjectsCount.setString(sf::String(std::to_string(m_EnityManager->m_Entities.size())));
    int numebr = m_EnityManager->m_Entities.size();
    numebr *= 19;
    m_Window.draw(m_Fps);
    m_Window.draw(m_FpsCount);
    m_Window.draw(m_Objects);
    m_Window.draw(m_ObjectsCount);

  
}
