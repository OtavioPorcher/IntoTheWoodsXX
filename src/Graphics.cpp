#include "Managers/Graphics.h"
#define WIDTH 800
#define HEIGHT 600

using namespace Managers;

Graphics* Graphics::instance = nullptr;
//incompleto e talvez no lugar errado
float Graphics::dt = 0;

Graphics::Graphics() {
    window = (new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Into the woods++"));
}
Graphics::~Graphics() {
    delete(window);
}
void Graphics::render(sf::RectangleShape* body) {
    window->draw(*body);
}
void Graphics::render(sf::Text* text) {
    window->draw(*text);
}