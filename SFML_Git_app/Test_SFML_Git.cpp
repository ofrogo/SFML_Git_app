#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1600, 900), "SFML works!");
	CircleShape shape(100.f);
	shape.setFillColor(Color::Green);

	Texture t;
	t.loadFromFile("font.jpg");

	Texture g;
	g.loadFromFile("nyan_cat_t.png");

	Sprite s;
	s.setTexture(t);

	Sprite gs(g,IntRect(20,10,70,30));

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		
		window.draw(s);
		window.draw(gs);
		window.display();
		
	}

	return 0;
}