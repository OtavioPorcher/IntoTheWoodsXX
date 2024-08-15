#pragma once

#include <SFML/Graphics.hpp>

namespace Managers {

    class Graphics {
    private:
        sf::RenderWindow* window;
        sf::View view;
        std::map<const char*, sf::Texture*> textureMap;
        sf::Clock clock;
        sf::Font* font;
        static float dt;
        static Managers::Graphics* instance;
        Graphics();
    public:
        ~Graphics();
        static Graphics* getInstance();
        void Render(sf::RectangleShape* body);
        void Render(sf::Text* text);
        void display();
        void clear();
        bool isWindowOpen() const;
        void closeWindow();
        void handleWindowSize();
        sf::Vector2u getWindowSize() const;
        void centerView(Math::CoordF pos);
        sf::Texture* loadTexture(const char* path);
        sf::Font* getFont();
        void updateDeltaTime();
    };
}