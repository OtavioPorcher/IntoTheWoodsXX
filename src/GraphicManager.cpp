#include "..\Include\Managers\GraphicManager.h"


using namespace Managers;




GraphicManager::GraphicManager() {
    window = (new sf::RenderWindow(sf::VideoMode(RES_X, RES_Y), "Into the woods++"));
}
GraphicManager::~GraphicManager() {
    delete(window);
}
void GraphicManager::render(sf::RectangleShape* body) {
    window->draw(*body);
}
void GraphicManager::render(sf::Text* text) {
    window->draw(*text);
}

float GraphicManager::dt(0.0f);
GraphicManager* GraphicManager::instance(NULL);