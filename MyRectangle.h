#pragma once

struct Coord {

	int x;
	int y;

};

class MyRectangle
{	
private:

	struct Coord {
		int x;
		int y;
	};

	char symbol;
	float height;
	float width;	
	Coord coord;

	inline bool IsCorrectSize(int size) const
	{
		return size > 0;
	}

	inline bool IsCorrectCoord(int coord) const
	{
		return coord >= 0;
	}

public:

	MyRectangle();

	MyRectangle(float _size);

	MyRectangle(float _width, float _height);	   

	void Print() const;
	
	void ChangeSize(float newWidth, float newHeight);	

	void ChangeCoord(int dx, int dy);

	void SetSymbol(char _symbol);
	
};

