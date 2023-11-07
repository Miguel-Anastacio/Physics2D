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

    
}

Application::~Application()
{
  
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

    while (m_Window.isOpen())
    {
        sf::Event event;
        while (m_Window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_Window.close();
            }
        }

        m_Window.clear();
        m_Window.display();
    }
}
