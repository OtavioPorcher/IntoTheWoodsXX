#include "..\Include\Managers\GraphicManager.h"


using namespace Managers;

Graphics* Graphics::instance = nullptr;
//incompleto e talvez no lugar errado
float Graphics::dt = 0;

Graphics::Graphics() {
    window = (new sf::RenderWindow(sf::VideoMode(RES_X, RES_Y), "Into the woods++"));
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