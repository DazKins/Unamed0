#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <string>
#include <memory>

namespace Display
{
    void init(int width, int height, const std::string& title);
    void create();
    bool wasCloseRequested();
    void update();
    void close();
    bool isOpen();

    int getWidth();
    int getHeight();
}

#endif // DISPLAY_H_INCLUDED
