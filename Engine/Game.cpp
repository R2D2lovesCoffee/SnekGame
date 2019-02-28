#include "MainWindow.h"
#include "Game.h"
#include<stdlib.h>
Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if ((canMoveDown)&& wnd.kbd.KeyIsPressed(VK_DOWN) && (!wnd.kbd.KeyIsPressed(VK_UP)) && (!wnd.kbd.KeyIsPressed(VK_RIGHT)) && (!wnd.kbd.KeyIsPressed(VK_LEFT))) {
		canMoveUp = false;
		canMoveDown = true;
		canMoveLeft = true;
		canMoveRight = true;

		dwp = true;
		lwp = rwp = uwp = false;

		//snek.move(Direction::DOWN);
	}
	if ((canMoveLeft)&& wnd.kbd.KeyIsPressed(VK_LEFT) && (!wnd.kbd.KeyIsPressed(VK_UP)) && (!wnd.kbd.KeyIsPressed(VK_RIGHT)) && (!wnd.kbd.KeyIsPressed(VK_DOWN))) {
		lwp = true;
		dwp = uwp = rwp = false;

		canMoveDown = true;
		canMoveUp = true;
		canMoveRight = false;
		canMoveLeft = true;

		//snek.move(Direction::LEFT);
	}
	if ((canMoveUp)&& wnd.kbd.KeyIsPressed(VK_UP) && (!wnd.kbd.KeyIsPressed(VK_LEFT)) && (!wnd.kbd.KeyIsPressed(VK_RIGHT)) && (!wnd.kbd.KeyIsPressed(VK_DOWN))) {
		canMoveDown = false;
		canMoveUp = true;
		canMoveRight = true;
		canMoveLeft = true;

		uwp = true;
		dwp = lwp = rwp = false;

		//snek.move(Direction::UP);
	}
	if ((canMoveRight)&& wnd.kbd.KeyIsPressed(VK_RIGHT) && (!wnd.kbd.KeyIsPressed(VK_LEFT)) && (!wnd.kbd.KeyIsPressed(VK_UP)) && (!wnd.kbd.KeyIsPressed(VK_DOWN))) {
		rwp = true;
		dwp = lwp = uwp = false;

		canMoveDown = true;
		canMoveUp = true;
		canMoveRight = true;
		canMoveLeft = false;

		//snek.move(Direction::RIGHT);
	}
	if (dwp) {
		if (canMoveDown) {
			snek.move(Direction::DOWN);
			Sleep(25);
		}
	}
	if (uwp) {
		if (canMoveUp) {
			snek.move(Direction::UP);
			Sleep(25);
		}
	}
	if (lwp) {
		if (canMoveLeft) {
			snek.move(Direction::LEFT);
			Sleep(25);
		}
	}
	if (rwp) {
		if (canMoveRight) {
			snek.move(Direction::RIGHT);
			Sleep(25);
		}
	}
	if (snekEats())
	{
		generateFood();
		snek.grow();
	}
	if (snakeHitWall()||tailHungry())
		gameOver();
}

void Game::ComposeFrame()
{
	if (start) {
		generateFood();
		start = 0;
	}
	gfx.DrawSnake(snek);
	gfx.PutGameObject(wall);
	gfx.PutGameObject(*food);
}
