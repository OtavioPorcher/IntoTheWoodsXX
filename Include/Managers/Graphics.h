#pragma once

#include <SFML/Graphics.hpp>
//incompleto ainda
namespace Managers {

    class Graphics {
    private:
        sf::RenderWindow* window;
        sf::View view;
        std::map<const char*, sf::Texture*> textureMap;
        sf::Clock clock;
        sf::Font* font;
        static Managers::Graphics* instance;
        Graphics();
    public:
        ~Graphics();
        static Graphics* getInstance();
        void Render(sf::RectangleShape* body); //Pode ser sprite
        void Render(sf::Text* text);
        void display();
        void clear();
        bool isWindowOpen();
        void closeWindow();
        void handleWindowSize();
        sf::Vector2u getWindowSize() const;

    };
}