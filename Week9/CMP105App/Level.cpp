#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	font.loadFromFile("font/arial.ttf");
	// initialise game objects
	text1.setFont(font);
	text1.setPosition(sf::Vector2f(0, 0));
	text1.setString(std::to_string(0));
	text1.setCharacterSize(46);
	text1.setFillColor(sf::Color::White);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		input->setKeyUp(sf::Keyboard::Space);
		beachBallManager.spawn();
	}

	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		input->setKeyUp(sf::Keyboard::Enter);
		goombaManager.spawn();
	}
}

// Update game objects
void Level::update(float dt)
{
	beachBallManager.update(dt);
	goombaManager.update(dt);
	text1.setString(std::to_string(goombaManager.getEntities()));
}

// Render level
void Level::render()
{
	beginDraw();
	beachBallManager.render(window);
	goombaManager.render(window);
	window->draw(text1);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}