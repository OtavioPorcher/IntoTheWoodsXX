#include "..\Include\Managers\GraphicManager.h"
using namespace Managers;

#include <iostream>

GraphicManager::GraphicManager():
    window(sf::VideoMode(RES_X, RES_Y), "IntoTheWoods++"),
    view(window.getView())
{
    
}
GraphicManager* GraphicManager::getInstance()
{
    if (!instance)
    {
        try { instance = new GraphicManager(); }
        catch (int error)
        {
            if (!error)
            {
                std::cout << "ERROR: Failed to Allocate Memory (Graphic Manager)" << std::endl;
                exit(1);
            }
        }
    }
    return instance;
}

GraphicManager::~GraphicManager() 
{

}

void GraphicManager::display()
{
    window.display();
}

void GraphicManager::clear()
{
    window.clear();
}

const bool GraphicManager::isWindowOpen()const
{
    return window.isOpen();
}

void GraphicManager::closeWindow()
{
    window.close();
}

sf::RenderWindow* GraphicManager::getWindow()
{
    return (&window);
}

void GraphicManager::centerView(sf::Vector2f pos)
{
    view.setCenter(pos);
    window.setView(view);
}

void GraphicManager::checkStutter(float dt)
{
    if (dt > 0.3f)
    {
        std::cout << "STUTTER DETECTED" << std::endl;
    }
}

GraphicManager* GraphicManager::instance(NULL);