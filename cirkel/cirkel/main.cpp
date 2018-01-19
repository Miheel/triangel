#include <Windows.h>
#include "SFML\Graphics.hpp"
int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{
	sf::RenderWindow window(sf::VideoMode(1200, 800), "hasse");
	window.setFramerateLimit(60);


	sf::CircleShape circle(5);

	float x = 200, y = 200;
	float velocity = 2;
	float vx = 0, vy = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			vx = -velocity;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			vy = -velocity;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			vx = velocity;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			vy = velocity;
		}

		x += vx;
		y += vy;
		vx = vy = 0;
		circle.setPosition(x, y);

		window.clear();
		window.draw(circle);
		window.display();
	}
	
	return 0;
}