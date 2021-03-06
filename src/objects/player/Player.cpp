#include "Player.h"
#include "../GameItem.h"

#include <iostream>
#include <string>
#include <cmath>
#include "windows.h"

Player::Player()
{
}

Player::Player(std::string texturePath, int x, int y)
{
	sf::Texture texture;
	if (!texture.loadFromFile(texturePath))
	{
		std::cout << "Nicht geladen" << std::endl;
	}
	sprite.setTexture(texture);
}

Player::Player(sf::Texture &texture, int x, int y, int num)
{
	sprite.setTexture(texture);
	sprite.setPosition(x, y);

	switch(num)
	{
		case 1:
			player1TextureBehind.loadFromFile("res/Character/Char1_behind_walk_right.png");
			player1TextureBehindWalk.loadFromFile("res/Character/Char1_behind_walk_left.png");
			player1TextureLeft.loadFromFile("res/Character/Char1_left_walk.png");
			player1TextureLeftWalk.loadFromFile("res/Character/Char1_left.png");
			player1TextureFront.loadFromFile("res/Character/Char1_front_walk-right.png");
			player1TextureFrontWalk.loadFromFile("res/Character/Char1_front_walk-left.png");
			player1TextureRight.loadFromFile("res/Character/Char1_right_walk.png");
			player1TextureRightWalk.loadFromFile("res/Character/Char1_right.png");	
			break;	
		case 2:
			player1TextureBehindWalk.loadFromFile("res/Character/Char2/Char1_behind_walk_left.png");
			player1TextureBehind.loadFromFile("res/Character/Char2/Char1_behind_walk_right.png");
			player1TextureFrontWalk.loadFromFile("res/Character/Char2/Char1_front_walk-left.png");
			player1TextureFront.loadFromFile("res/Character/Char2/Char1_front_walk-right.png");
			player1TextureLeft.loadFromFile("res/Character/Char2/Char1_left_walk.png");
			player1TextureRight.loadFromFile("res/Character/Char2/Char1_right_walk.png");
			player1TextureLeftWalk.loadFromFile("res/Character/Char2/Char2_left.png");	
			player1TextureRightWalk.loadFromFile("res/Character/Char2/Char2_right.png");
			break;	
		case 3:
			player1TextureBehindWalk.loadFromFile("res/Character/Char3/Char1_behind_walk_left.png");
			player1TextureBehind.loadFromFile("res/Character/Char3/Char1_behind_walk_right.png");
			player1TextureFrontWalk.loadFromFile("res/Character/Char3/Char1_front_walk-left.png");
			player1TextureFront.loadFromFile("res/Character/Char3/Char1_front_walk-right.png");
			player1TextureLeft.loadFromFile("res/Character/Char3/Char1_left_walk.png");
			player1TextureRight.loadFromFile("res/Character/Char3/Char1_right_walk.png");
			player1TextureLeftWalk.loadFromFile("res/Character/Char3/Char3_left.png");	
			player1TextureRightWalk.loadFromFile("res/Character/Char3/Char3_right.png");	
			break;	
		case 4:
			player1TextureBehindWalk.loadFromFile("res/Character/Char4/Char1_behind_walk_left.png");
			player1TextureBehind.loadFromFile("res/Character/Char4/Char1_behind_walk_right.png");
			player1TextureFrontWalk.loadFromFile("res/Character/Char4/Char1_front_walk-left.png");
			player1TextureFront.loadFromFile("res/Character/Char4/Char1_front_walk-right.png");
			player1TextureLeft.loadFromFile("res/Character/Char4/Char1_left_walk.png");
			player1TextureRight.loadFromFile("res/Character/Char4/Char1_right_walk.png");
			player1TextureLeftWalk.loadFromFile("res/Character/Char4/Char4_left.png");	
			player1TextureRightWalk.loadFromFile("res/Character/Char4/Char4_right.png");	
			break;	
	}
}

sf::Sprite Player::getSprite()
{
	return sprite;
}

void Player::movePlayer(std::string direction, float playerPositionX, float playerPositionY)
{
	if (direction.compare("up") == 0)
	{
		goUp(playerPositionX, playerPositionY);
	}
	else if (direction.compare("left") == 0)
	{
		goLeft(playerPositionX, playerPositionY);
	}
	else if (direction.compare("down") == 0)
	{
		goDown(playerPositionX, playerPositionY);
	}
	else if (direction.compare("right") == 0)
	{
		goRight(playerPositionX, playerPositionY);
	}
}

sf::Vector2f Player::getHitbox()
{
	return hitbox;
}

sf::Vector2f Player::getHitboxOffset()
{
	return hitboxOffset;
}

void Player::incBombPower(int i)
{
	bombPower += i;
}

void Player::goUp(float playerPositionX, float playerPositionY)
{
	sprite.setPosition(round(playerPositionX / 64) * 64, playerPositionY - speed);
	if (upwalk < 9)
	{
		sprite.setTexture(player1TextureBehind);
		upwalk++;
	}
	else if (upwalk > 8)
	{
		sprite.setTexture(player1TextureBehindWalk);
		upwalk++;
		if (upwalk > 16)
		{
			upwalk = 0;
		}
	}
	else
	{
		upwalk++;
	}
}

void Player::goLeft(float playerPositionX, float playerPositionY)
{
	sprite.setPosition(playerPositionX - speed, round(playerPositionY / 64) * 64);
	if (leftwalk < 9)
	{
		sprite.setTexture(player1TextureLeft);
		leftwalk++;
	}
	else if (leftwalk > 8)
	{
		sprite.setTexture(player1TextureLeftWalk);
		leftwalk++;
		if (leftwalk > 16)
		{
			leftwalk = 0;
		}
	}
	else
	{
		leftwalk++;
	}
}

void Player::goDown(float playerPositionX, float playerPositionY)
{
	sprite.setPosition(round(playerPositionX / 64) * 64, playerPositionY + speed);
	if (downwalk < 9)
	{
		sprite.setTexture(player1TextureFront);
		downwalk++;
	}
	else if (downwalk > 8)
	{
		sprite.setTexture(player1TextureFrontWalk);
		downwalk++;
		if (downwalk > 16)
		{
			downwalk = 0;
		}
	}
	else
	{
		downwalk++;
	}
}

void Player::goRight(float playerPositionX, float playerPositionY)
{
	sprite.setPosition(playerPositionX + speed, round(playerPositionY / 64) * 64);
	if (rightwalk < 9)
	{
		sprite.setTexture(player1TextureRight);
		rightwalk++;
	}
	else if (rightwalk > 8)
	{
		sprite.setTexture(player1TextureRightWalk);
		rightwalk++;
		if (rightwalk > 16)
		{
			rightwalk = 0;
		}
	}
	else
	{
		rightwalk++;
	}
}

void Player::addBomb()
{
	bombs++;
}

void Player::decBomb()
{
	bombs--;
}

int Player::getBombC()
{
	return bombs;
}

Player::~Player()
{
}

int Player::getSpeed()
{
}
void Player::addSpeed(int s)
{
	int tempSpeed = speed + s;
	if (tempSpeed >= 8)
	{
		speed = 8;
	}
	else
	{
		speed += s;
	}
}
