#include "Square.h"
class GameObject {
protected:
	Square* body;
	int speedX = 0;
	int speedY = 0;
	int noParts;
public:
	GameObject(){}
	Square * getBody() { return this->body; }
	int getNoParts() { return this->noParts; }
	void setColor(Color value) {
		for (int i = 0; i < this->noParts; i++)
			this->body[i].setColor(value);
	}
	GameObject(Square* body, int noParts) {
		this->noParts = noParts;
		this->body = new Square[noParts];
		for (int i = 0; i < noParts; i++)
			this->body[i] = body[i];
	}
	GameObject(Square* body, int noParts, int speedX, int speedY) {
		this->noParts = noParts;
		this->body = new Square[noParts];
		for (int i = 0; i < noParts; i++)
			this->body[i] = body[i];
		this->speedX = speedX;
		this->speedY = speedY;
	}
	Pixel RighestPixel() {
		Pixel p = this->body[0].getPixels()[0];
		for (int i = 0; i < this->noParts; i++)
			for (int j = 0; j < this->body[i].getWidth()*this->body[i].getHeight(); j++)
				if (this->body[i].getPixels()[j].getX() > p.getX())
					p = this->body[i].getPixels()[j];
		return p;
	}
	Pixel LeftestPixel() {
		Pixel p = this->body[0].getPixels()[0];
		for (int i = 0; i < this->noParts; i++)
			for (int j = 0; j < this->body[i].getWidth()*this->body[i].getHeight(); j++)
				if (this->body[i].getPixels()[j].getX() < p.getX())
					p = this->body[i].getPixels()[j];
		return p;
	}
	Pixel HighestPixel() {
		Pixel p = this->body[0].getPixels()[0];
		for (int i = 0; i < this->noParts; i++)
			for (int j = 0; j < this->body[i].getWidth()*this->body[i].getHeight(); j++)
				if (this->body[i].getPixels()[j].getY() < p.getY())
					p = this->body[i].getPixels()[j];
		return p;
	}
	Pixel DownestPixel() {
		Pixel p = this->body[0].getPixels()[0];
		for (int i = 0; i < this->noParts; i++)
			for (int j = 0; j < this->body[i].getWidth()*this->body[i].getHeight(); j++)
				if (this->body[i].getPixels()[j].getY() > p.getY())
					p = this->body[i].getPixels()[j];
		return p;
	}
	void move() {
		for(int i = 0;i<this->noParts;i++)
			for (int j = 0; j < this->body[i].getWidth() * this->body[i].getHeight(); j++)
			{
				this->body[i].getPixels()[j].setX(this->body[i].getPixels()[j].getX() + speedX);
				this->body[i].getPixels()[j].setY(this->body[i].getPixels()[j].getY() + speedY);
			}
	}
	void moveUp(int speed) {
		this->speedX = 0;
		if (HighestPixel().getY() - speed >= 0){
			this->speedY = -speed;
			this->move();
		}
		else if (HighestPixel().getY() > 0){
			this->speedY = -1;
			this->move();
		}
	}
	void moveDown(int speed) {
		this->speedX = 0;
		if (DownestPixel().getY() + speed <= 599) {
			this->speedY = speed;
			this->move();
		}
		else if (DownestPixel().getY() < 599) {
			this->speedY = 1;
			this->move();
		}
	}
	void moveLeft(int speed) {
		this->speedY = 0;
		if (LeftestPixel().getX() - speed >= 0) {
			this->speedX = -speed;
			this->move();
		}
		else if (LeftestPixel().getX() > 0) {
			this->speedX = -1;
			this->move();
		}
	}
	void moveRight(int speed) {
		this->speedY = 0;
		if (RighestPixel().getX() + speed <= 799) {
			this->speedX = speed;
			this->move();
		}
		else if (RighestPixel().getX() < 799) {
			this->speedX = 1;
			this->move();
		}
	}
	~GameObject(){
		delete[] this->body;
	}
};