#pragma once
#include"Colors.h"
class Pixel {
private:
	int x;
	int y;
	Color color;
public:
	Pixel() {
		this->x = 0;
		this->y = 0;
		this->color = Color(0, 0, 0);
	}
	Pixel(int x, int y, Color color) {
		if (checkWidth(x) && checkHeight(y)){
			this->x = x;
			this->y = y;
			this->color = color;
		}
	}
	Pixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
		if (checkWidth(x) && checkHeight(y)) {
			this->x = x;
			this->y = y;
			this->color = Color(r, g, b);
		}
	}
	int getX() { return this->x; }
	int getY() { return this->y; }
	Color getColor() { return this->color; }
	
	void setX(int value) { if(checkWidth(value)) this->x = value; }
	void setY(int value) { if(checkHeight(value)) this->y = value; }
	void setColor(Color value) { this->color = value; }

	
	static bool checkWidth(int x) {
		return x >= 0 && x < 800;
	}
	static bool checkHeight(int y) {
		return y >= 0 && y < 600;
	}
};