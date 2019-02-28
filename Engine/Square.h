#include "Pixel.h"
#include "Location.h"
class Square {
private:
	int width;
	int height;
	Location location;
	Pixel* pixels;
public:
	Square() {}
	Square(int width, int height, Location loc) {
		location.x = loc.x;
		location.y = loc.y;
		this->width = width;
		this->height = height;
		this->pixels = new Pixel[width*height];
		int k = 0;
		int nr = 0;
		while (k < height) {
			for (int i = 0; i < width; i++)
			{
				this->pixels[nr] = Pixel(loc.x + i, loc.y + k, Color(255, 255, 255));
				nr++;
			}
			k++;
		}
	}
	Square(int width, int height, Location loc, Color color) {
		location.x = loc.x;
		location.y = loc.y;
		this->width = width;
		this->height = height;
		this->pixels = new Pixel[width*height];
		int k = 0;
		int nr = 0;
		while (k < height) {
			for (int i = 0; i < width; i++)
			{
				this->pixels[nr] = Pixel(loc.x + i, loc.y + k, color);
				nr++;
			}
			k++;
		}
	}
	Location getLocation() { return this->location; }
	int getWidth() { return this->width; }
	int getHeight() { return this->height; }
	Pixel* getPixels() { return this->pixels; }
	void setColor(Color value) {
		for (int i = 0; i < width*height; i++)
			this->pixels[i].setColor(value);
	}
};