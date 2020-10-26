#pragma once
#include<iostream>
#include<vector>
#include<ctime>
#include<SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
using namespace sf;
using namespace std;
/*
Class that acts as the game engine.

*/
class Game
{

private:
	//Variable  
	//window
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;

	//Mouse position
	Vector2i mousePosiWindow;

	//Game logic
	int point;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	//Private funtions
	void initVariables();
	void initwindow();
	void initEnemy();
	//Game object
	vector<RectangleShape> enemies;
	RectangleShape enemy;

public:
	//Construvtors /Destructors
	Game();
	virtual ~Game();
	//Accessors
	const bool windowRuning() const;
	//Funtion
	void spwanEnemy();
	void pollEvent();
	void updateMousePositions();
	void updateEnmies();
	void update();
	void render();
	void renderEnmies();


};

