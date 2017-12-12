#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1600, 900), "SFML works!");
	

	Texture t;
	t.loadFromFile("font.jpg");

	Texture g;
	g.loadFromFile("nyan_cat_t.png");

	Sprite s;
	s.setTexture(t);

	IntRect rectNyanCat(0, 0, 63, 30);
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
			if (rectNyanCat.left == 126)
				rectNyanCat.left = 0;
			else
				rectNyanCat.left += 63;

			gs.setTextureRect(rectNyanCat);
			clock.restart();
		}


		window.clear();
		window.draw(s);
		window.draw(gs);
		window.display();
		
	}

	return 0;
}