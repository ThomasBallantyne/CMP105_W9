#pragma once
#include "Goomba.h"
#include <math.h>
#include <vector>
#include <iostream>
class GoombaManager
{
public:
	GoombaManager();
	~GoombaManager();

	void spawn();
	void update(float dt);
	void deathCheck();
	void render(sf::RenderWindow* window);
	int getEntities();

private:
	std::vector<Goomba> goombas;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
};

