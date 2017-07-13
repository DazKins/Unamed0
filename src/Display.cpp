#include "Display.h"

namespace Display
{
    int WIN_WIDTH = 0;
    int WIN_HEIGHT = 0;
    std::string WIN_TITLE = "";

    std::unique_ptr<sf::Window> WIN;

    void init(int width, int height, const std::string& title)
    {
        WIN_WIDTH = width;
        WIN_HEIGHT = height;
        WIN_TITLE = title;
    }

    void create()
    {
        sf::VideoMode videoMode (WIN_WIDTH, WIN_HEIGHT, 32);

        sf::ContextSettings contextSettings;
        contextSettings.depthBits = 24;
        contextSettings.majorVersion = 3;
        contextSettings.minorVersion = 3; //OpenGL 3.3

        WIN = std::make_unique<sf::Window>(videoMode, WIN_TITLE, sf::Style::Close, contextSettings);

        WIN->setMouseCursorVisible(false);
    }

    bool wasCloseRequested()
    {
        sf::Event e;
        while (WIN->pollEvent(e))
        {
            if (e.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                return true;
            }
        }
        return false;
    }

    void close()
    {
        WIN->close();
    }

    void update()
    {
        WIN->display();
    }

    bool isOpen()
    {
        return WIN->isOpen();
    }

    int getWidth()
    {
        return WIN_WIDTH;
    }

    int getHeight()
    {
        return WIN_HEIGHT;
    }
}
