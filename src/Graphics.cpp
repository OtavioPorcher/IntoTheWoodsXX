#include "Graphics.h"
#define WIDTH 800
#define HEIGHT 600

Graphics* Graphics::instance = nullptr;
//incompleto e talvez no lugar errado
Graphics::Graphics() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Into the woods++");
}
Graphics::~Graphics() {
    delete();
}
