#include "Application.h"
#include "Entities/Circle.h"
#include "Entities/Aabb.h"
#include "Entities/Polygon.h"
#include "imgui-SFML/imgui-SFML.h"

Application::Application()
    : m_Window( 
        sf::VideoMode(1400, 980),
        "WINDOW_NAME",
        sf::Style::Default,
        sf::ContextSettings(0, 0, 8)
    )
{
    //InitGLFW();
    //// Initialize GLEW (must be done after an OpenGL context is created)
    //glewInit();
    m_EnityManager = new EntityManager(1400, 980);
    
    if (m_Font.loadFromFile("fonts/Roboto-Bold.ttf"))
    {

        m_Fps.setFont(m_Font);
        m_FpsCount.setFont(m_Font);
        m_Objects.setFont(m_Font);
        m_ObjectsCount.setFont(m_Font);
        m_CollisionsBPCount.setFont(m_Font);
        m_CollisionsCount.setFont(m_Font);
    }

    m_Fps.setPosition(sf::Vector2f(0, 0));
    m_FpsCount.setPosition(sf::Vector2f(300, 0));
    m_Fps.setFillColor(sf::Color::Green);
    m_FpsCount.setFillColor(sf::Color::Green);
    m_Objects.setPosition(sf::Vector2f(0, 50));
    m_ObjectsCount.setPosition(sf::Vector2f(300, 50));
    m_Objects.setFillColor(sf::Color::Green);
    m_ObjectsCount.setFillColor(sf::Color::Green);
    m_CollisionsBPCount.setFillColor(sf::Color::Red);
    m_CollisionsBPCount.setPosition(0, 100);
    m_CollisionsCount.setFillColor(sf::Color::Green);
    m_CollisionsCount.setPosition(0, 150);

    bool NoMove = false;
    bool NoResize = false;
    bool NoCollapse = true;
    m_EngineData = std::make_unique<EngineDataUI>(NoMove, NoResize, NoCollapse, "Engine Data", true);

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
    ImGui::SFML::Init(m_Window);
    //m_Window.setFramerateLimit(60.0f);
    sf::Clock clock;
    // Create Some Static Objects
    Aabb Floor(sf::Vector2f(500, 500), Physics2D::Vector2(400, 50));
    Floor.GetRigidbody()->SetIsKinematic(false);
    Floor.GetShape()->setFillColor(sf::Color::Red);
    Floor.GetShape()->setOutlineColor(sf::Color::White);

    auto& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

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
            ImGui::SFML::ProcessEvent(m_Window, event);
            if (event.type == sf::Event::Closed)
            {
                m_Window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && !m_EngineData->HoveringUI)
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

                        for (int i = 0; i < 1; i++)
                        {                        
                            //m_EnityManager->AddEntity(Circle(positionFloat, 10.0f));
                            m_EnityManager->AddEntity(Circle(positionFloat,m_EngineData->GetBodyRadius(), m_EngineData->GetBodySpecs(), m_EngineData->GetCircleColor()));
                            m_World.m_CollisionBodies.emplace_back(m_EnityManager->GetEntities().back().GetRigidbody());
                            positionFloat.x +=  20;
                        }
                    }
                    if (event.mouseButton.button == sf::Mouse::Right)
                    {
                         //m_EnityManager->AddEntity(Aabb(positionFloat, Physics2D::Vector2(25, 25)));
                         //m_EnityManager->AddEntity(Aabb(positionFloat, m_EngineData->GetBodySize(), m_EngineData->GetBodySpecs()));
                         m_EnityManager->AddEntity(Aabb(positionFloat, m_EngineData->GetBodySize(), m_EngineData->GetBodySpecs(), m_EngineData->GetAabbColor()));
                         //m_EnityManager->AddEntity(Polygon(positionFloat, m_EngineData->GetBodySpecs(), m_EngineData->GetAabbColor(), 5));
                         m_World.m_CollisionBodies.emplace_back(m_EnityManager->GetEntities().back().GetRigidbody());

                    }
                }
                    //m_EnityManager
            }
            else if(event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Delete)
                {
                    m_EnityManager->m_Entities.clear();
                    m_World.m_CollisionBodies.clear();

                    // add floor
                    m_EnityManager->AddEntity(Floor);
                    //m_EnityManager->m_Entities.push_back(Aabb(sf::Vector2f(100, 500), Physics2D::Vector2(400, 50)));
                    m_World.m_CollisionBodies.emplace_back(m_EnityManager->GetEntities().back().GetRigidbody());

                }

            }
        }

        m_World.Step(deltaTime.asSeconds());
        m_EnityManager->UpdateEntities(deltaTime.asSeconds());

        // this cleanup should be more efficient
        // look into how to improve
        m_World.CleanupCollisionBodies(m_EnityManager->CleanupEntities());

        ImGui::SFML::Update(m_Window, deltaTime);
        //ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
        //ImGui::ShowDemoWindow();
      /*  ImGui::Begin("Test");
        ImGui::Text("Hey");
        ImGui::End();*/

        m_Window.clear();

        for (const auto& ent : m_EnityManager->GetEntities())
        {
            m_Window.draw(ent);
        }

        RenderDebugInfo(deltaTime.asSeconds(), m_World.CollisionsBP, m_World.Collisions);
        ImGui::SFML::Render(m_Window);
        m_Window.display();
    }
}

void Application::RenderDebugInfo(float dt, int collisionsBP, int collisions)
{
   float fps = 1 / dt;
   /* m_FpsCount.setString(sf::String(std::to_string(fps)));
    m_ObjectsCount.setString(sf::String(std::to_string(m_EnityManager->m_Entities.size())));
    m_CollisionsBPCount.setString(sf::String(std::to_string(collisionsBP)));
    m_CollisionsCount.setString(sf::String(std::to_string(collisions)));
    int numebr = m_EnityManager->m_Entities.size();
    numebr *= 19;
    m_Window.draw(m_Fps);
    m_Window.draw(m_FpsCount);
    m_Window.draw(m_Objects);
    m_Window.draw(m_ObjectsCount);
    m_Window.draw(m_CollisionsBPCount);
    m_Window.draw(m_CollisionsCount);*/
   float objCOunt = m_EnityManager->m_Entities.size();
   m_EngineData->SetData({
       Data("Fps", fps),
       Data("Object Count", (float)m_EnityManager->m_Entities.size()),
       Data("Collision Count", collisions)
   });
   m_EngineData->RenderPanel();

  
}

