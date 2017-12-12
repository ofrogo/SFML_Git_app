#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1600, 900), "SFML works!");
	

	Texture t;
	t.loadFromFile("font.jpg");

	Texture g;
	g.loadFromFile("nyan_cat_t_2 (1).png");

	Sprite s;
	s.setTexture(t);

	IntRect rectNyanCat(0, 0, 119, 48);
	Sprite gs(g,rectNyanCat);

	Clock clock;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (clock.getElapsedTime().asSeconds() > 0.1f) {
			if (rectNyanCat.left == 357)
				rectNyanCat.left = 0;
			else
				rectNyanCat.left += 119;

			gs.setTextureRect(rectNyanCat);
			clock.restart();
		}

		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			gs.move(0, -1);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			gs.move(0, 1);
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			gs.move(-1, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			gs.move(1, 0);
		}


		window.clear();
		window.draw(s);
		window.draw(gs);
		window.display();
		
	}

	return 0;
}