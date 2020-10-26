#include<SFML/Graphics.hpp>
#include<iostream>>
#include "Player.h"
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(512, 512), "SFML", Style::Close | Style::Resize);
	Texture playerTexture;
	playerTexture.loadFromFile("megaman 02.png");
	Player player(&playerTexture, Vector2u(3, 2), 0.3f,300.0f);
	float deltaTime = 0.0f;
	Clock clock;

	
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case Event::Closed:
				window.close();
				break;

			}
		}

		player.update(deltaTime);
	window.clear(Color(150,150,150));
	player.Draw(window);
	window.display();
	}


}