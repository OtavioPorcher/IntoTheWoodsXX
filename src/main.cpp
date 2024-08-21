#include <SFML/Graphics.hpp>
#include "..\Include\Game.h"
int main()
{
    Game* Principal = Game::getInstance();
    Principal->executar();

    return 0;
}