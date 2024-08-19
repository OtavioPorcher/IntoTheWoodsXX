#pragma once

#include <SFML/Graphics.hpp>
#include "..\Properties\GraphicProps.h"

namespace Managers {

    class GraphicManager {
    private:
        static Managers::GraphicManager* instance;
        GraphicManager();

        sf::RenderWindow* window;
        sf::View view;
        //std::map<const char*, sf::Texture*> textureMap;
        sf::Clock clock;
        sf::Font* font;

        static float dt;
        
    public:
        static GraphicManager* getInstance();
        ~GraphicManager();
        
        void render(sf::RectangleShape* body);
        void render(sf::Text* text);
        void display();
        void clear();
        bool isWindowOpen() const;
        void closeWindow();
        void handleWindowSize();
        sf::Vector2u getWindowSize() const;
        void centerView(sf::Vector2f pos);
        sf::Texture* loadTexture(const char* path);
        sf::Font* getFont();
        void updateDeltaTime();
    };
}