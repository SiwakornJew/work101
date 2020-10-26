#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
class Animation
{
public:
	Animation(Texture* texture, Vector2u imageConut, float switchTime);
	~Animation();

	void Update(int row, float deltaTime, bool faceRight);
public:
	sf::IntRect uvRect;
private:
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

