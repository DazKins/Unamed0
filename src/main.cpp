#include <iostream>

#include "Display.h"
#include "Application.h"
#include "Util/OpenGLHelper.h"
#include "Maths/GLM.h"
#include "Graphics/Model/Model_Loader.h"
#include "Util/StringUtil.h"

#include <SFML/System/Clock.hpp>

int entry()
{
    std::cout << "Program starting..." << std::endl;

    Display::init(1280, 720, "Window");

    Display::create();

    OpenGLHelper::init(1280, 720);

    Application app;

    sf::Clock clock;

    //OpenGLHelper::setWireframeMode(true);

    sf::RectangleShape rectangle (sf::Vector2f(200, 40));

    while (Display::isOpen())
    {
        OpenGLHelper::clear();

        float dt = clock.getElapsedTime().asSeconds();
        clock.restart();

        app.tick(dt);
        app.render();

        Display::update();

        if (Display::wasCloseRequested())
            Display::close();
    }

    return 0;
}

int main()
{
    return entry();
}
