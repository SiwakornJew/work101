#include "Game.h"
using namespace sf;
//Funtions
Game::Game()
{
	this->initVariables();
	this->initwindow();
	this->initEnemy();

}
Game::~Game()
{
	delete this-> window;
}
const bool Game::windowRuning() const
{
	return this->window->isOpen();
}
//Private function
void Game::initVariables()
{
	this -> window = nullptr;
	//Game logic
	this->point = 0;
	this->enemySpawnTimer = 1000.f;
	this->enemySpawnTimerMax = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
}

void Game::initwindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window=new RenderWindow (this->videoMode, "Nigntmare of Spider", Style::Titlebar | Style::Close);
	this->window->setFramerateLimit(60); 
}
void Game::initEnemy()
{
	this->enemy.setPosition(10.f,10.f);
	this->enemy.setSize(Vector2f(100.f,100.f));
	this->enemy.setScale(Vector2f(0.5f, 0.5f));
	this->enemy.setFillColor(Color::Cyan);
	this->enemy.setOutlineColor(Color::Green);
	this->enemy.setOutlineThickness(1.f);


}
//Accessors

void Game::spwanEnemy()
{
	/*
	* @return void
	* spawn enemies and sets thier color and positions.
	*	-Sets a random position.
	*	-Sets a random color.
	*	-Adds enemy to the vector.

	*/
	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->enemy.getSize().y))
	);

	this->enemy.setFillColor(Color::Green);

	this->enemies.push_back(this->enemy);
}

void Game::pollEvent()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case Event::Closed:
				this->window->close();
				break;
		case Event::KeyPressed:
				if (this->ev.key.code == sf::Keyboard::Escape)
					this->window->close();
				break;

		}


	}

}
void Game::updateMousePositions()
{
	/*
	@ return void

	Update the mouse positions:
	* Mouse position relative to window (vector2i)
	*/
	this->mousePosiWindow = Mouse::getPosition(*this->window);

}
void Game::updateEnmies()
{
	/*
	@ return void

	Update the enemy spawn timer and spawns enemies:
	when the total amout of enemies is smaller than the maximum
	*/

	//Updating th etimer fpr enemy spawing
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			//spawn the enemy and reset the timer
			this->spwanEnemy();
			this->enemySpawnTimer = 0.f;
		}

		else
			this->enemySpawnTimer += 1.f;
	}
	for (auto &e : this->enemies)
	{
		e.move(0.f, 1.f);
	}
	
}
//Constructors /Destructors
void Game::update()
{
	this->pollEvent();

	this->updateMousePositions();

	this->updateEnmies();

}

void Game::render()
{
	/*
	-clear old frame
	-render objects
	-display frame in window
	Render the game object
	
	*/

	this->window->clear();
	//Draw game object
	this->window->draw(this->enemy);
	this->renderEnmies();

	this->window->display();
}

void Game::renderEnmies()
{
	for (auto &e : this->enemies)
	{
		this->window->draw(e);
	}
}
