#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	/********************************/
	Square* snakeBody = new Square[8]{ Square(10,10,Location(400,300)),Square(10,10,Location(410,300)),Square(10,10,Location(420,300)) ,Square(10,10,Location(430,300))
		,Square(10,10,Location(440,300)),Square(10,10,Location(450,300)),Square(10,10,Location(460,300)),Square(10,10,Location(470,300))
	};
	Snake snek = Snake(8,snakeBody, Color(0, 0, 255));
	Square* wallArea = new Square[4]{ Square(800, 10, Location(0,0)) ,
	Square(800,10,Location(0,590)),Square(10,780,Location(0,10)),Square(10,780,Location(790,10)) };
	GameObject wall = GameObject(wallArea, 4);
	int vectX[78] = { 10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780 };
	int vectY[58] = { 10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580 };
	GameObject *food = new GameObject(&Square(10, 10,Location(20,20)), 1);
	

	bool start = 1;
	bool gameover = false;
	bool dwp = false;
	bool uwp = false;
	bool rwp = false;
	bool lwp = false;

	bool canMoveLeft = true;
	bool canMoveRight = false;
	bool canMoveUp = true;
	bool canMoveDown = true;
	/********************************/
	/*  User Functions              */
	/********************************/
	bool snekEats() {
		if (snek.getBody()[0].getPixels()[0].getX() == (*food).getBody()[0].getPixels()[0].getX() &&
			snek.getBody()[0].getPixels()[0].getY() == (*food).getBody()[0].getPixels()[0].getY())
			return true;
		return false;
	}
	void generateFood() {
		Square* square = new Square(10, 10, Location(vectX[rand() % 78+1], vectY[rand() % 58+1]));
		food = new GameObject(square, 1);
		food->setColor(Color(255, 0, 0));
	}
	bool snakeHitWall() {
		if (snek.getBody()[0].getLocation().x == 0 || snek.getBody()[0].getLocation().x >= 790 ||
			snek.getBody()[0].getLocation().y == 0 || snek.getBody()[0].getLocation().y >= 590)
			return true;
		return false;
	}
	bool tailHungry() {
		for (int i = 0; i < snek.getNoParts()-2; i++)
			for (int j = i + 1; j < snek.getNoParts(); j++)
				if (snek.getBody()[i].getLocation().x == snek.getBody()[j].getLocation().x && snek.getBody()[i].getLocation().y == snek.getBody()[j].getLocation().y)
					return true;
		return false;
	}
	void gameOver() {
		canMoveLeft = canMoveRight = canMoveUp = canMoveDown = false;
	}
};