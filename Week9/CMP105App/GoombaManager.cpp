#include "GoombaManager.h"

GoombaManager::GoombaManager()
{
	texture.loadFromFile("gfx/Goomba.png");

	for (int i = 0; i < 40; i++)
	{
		goombas.push_back(Goomba());
		goombas[i].setAlive(false);
		goombas[i].setTexture(&texture);
		goombas[i].setSize(sf::Vector2f(100, 100));
	}
}

GoombaManager::~GoombaManager()
{

}

void GoombaManager::spawn()
{
	for (int i = 0; i < goombas.size(); i++)
	{
		if (!goombas[i].isAlive())
		{
			goombas[i].setAlive(true);
			goombas[i].setVelocity(0, 100);
			goombas[i].setPosition(rand() % 1100 + 1, -100);
		}
	}
}

void GoombaManager::update(float dt)
{
	for (int i = 0; i < goombas.size(); i++)
	{
		if (goombas[i].isAlive())
		{
			goombas[i].update(dt);
		}
	}
	deathCheck();
}

void GoombaManager::deathCheck()
{
	for (int i = 0; i < goombas.size(); i++)
	{
		if (goombas[i].isAlive())
		{
			if (goombas[i].getPosition().y > 600)
			{
				goombas[i].setAlive(false);
			}
		}
	}
}

void GoombaManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < goombas.size(); i++)
	{
		if (goombas[i].isAlive())
		{
			window->draw(goombas[i]);
		}
	}
}

int GoombaManager::getEntities()
{
	return (goombas.size());
}