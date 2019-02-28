#include "GameObject.h"
enum Direction{UP, DOWN, LEFT, RIGHT};
class Snake :public GameObject {
public:
	int* locX;
	int* locY;
	Snake(int length,Square* body, Color color) {
		this->noParts = length;
		this->body = new Square[400];
		for (int i = 0; i < noParts; i++)
			this->body[i] = body[i];
		locX = new int[400];
		locY = new int[400];
		for (int i = 0; i < noParts; i++)
			locX[i] = body[i].getLocation().x;
		for (int i = 0; i < noParts; i++)
			locY[i] = body[i].getLocation().y;
		this->setColor(color);
		
	}
	void move(Direction dir) {
		if (dir == Direction::DOWN) {
			Square temp = body[0];
			body[0] = Square(body[0].getWidth(), body[0].getHeight(), Location(body[0].getLocation().x, body[0].getLocation().y + 10), body[0].getPixels()[0].getColor());
			tailFollow(temp);
		}
		if (dir == Direction::UP) {
			Square temp = body[0];
			body[0] = Square(body[0].getWidth(), body[0].getHeight(), Location(body[0].getLocation().x, body[0].getLocation().y - 10), body[0].getPixels()[0].getColor());
			tailFollow(temp);
		}
		if (dir == Direction::LEFT) {
			Square temp = body[0];
			body[0] = Square(body[0].getWidth(), body[0].getHeight(), Location(body[0].getLocation().x - 3, body[0].getLocation().y), body[0].getPixels()[0].getColor());
			body[0] = Square(body[0].getWidth(), body[0].getHeight(), Location(body[0].getLocation().x - 3, body[0].getLocation().y), body[0].getPixels()[0].getColor());
			body[0] = Square(body[0].getWidth(), body[0].getHeight(), Location(body[0].getLocation().x - 4, body[0].getLocation().y), body[0].getPixels()[0].getColor());
			tailFollow(temp);
			
		}
		if (dir == Direction::RIGHT) {
			Square temp = body[0];
			body[0] = Square(body[0].getWidth(), body[0].getHeight(), Location(body[0].getLocation().x + 10, body[0].getLocation().y), body[0].getPixels()[0].getColor());
			tailFollow(temp);
		}
	}
	void tailFollow(Square temp) {
		Square temp2;
		for (int i = 1; i < noParts; i++) {
			temp2 = body[i];
			body[i] = temp;
			temp = temp2;
		}
	}
	void grow() {
		this->noParts++;
		body[noParts-1] = body[noParts - 2];
	}
};