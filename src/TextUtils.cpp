#include "../Include/Utils/TextUtils.h"

void setText(sf::Text* text, std::string txt)
{
	text->setString(txt);

	sf::FloatRect aux = text->getLocalBounds();
	text->setOrigin(aux.width / 2, aux.height / 2);
}