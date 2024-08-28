#pragma once

#include <SFML/Graphics.hpp>
#include "..\Properties\GraphicProps.h"

namespace Managers {

    class GraphicManager {
    private:
        static Managers::GraphicManager* instance;
        GraphicManager();

        sf::RenderWindow window;
        sf::View view;
        //std::map<const char*, sf::Texture*> textureMap;
        static sf::Font font;

     
    public:
        static GraphicManager* getInstance();
        ~GraphicManager();
        

        template<class type>
        void render(type* target) { window.draw(*target); }
        void display();
        void clear();

        const bool isWindowOpen() const;
        void closeWindow();
        //void handleWindowSize();
        //sf::Vector2u getWindowSize() const;
        sf::RenderWindow* getWindow(); // Necessário no gerenciador de eventos
        static sf::Font& getFont();

        void centerView(sf::Vector2f pos);
        //sf::Texture* loadTexture(const char* path);
        //sf::Font* getFont();
        void checkStutter(float dt);
    };
}