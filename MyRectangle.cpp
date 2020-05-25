#include "MyRectangle.h"
#include<iostream>

using namespace std;

MyRectangle::MyRectangle()
{
	symbol = '#';
	height = 1;
	width = 1;
	coord = { 0, 0 };
}

MyRectangle::MyRectangle(float _size) : MyRectangle() 
{
	height = (IsCorrectSize(_size) ? _size : 1);
	width = (IsCorrectSize(_size) ? _size : 1);
}

MyRectangle::MyRectangle(float _width, float _height) : MyRectangle()
{
	height = (IsCorrectSize(_height) ? _height : 1);
	width = (IsCorrectSize(_width) ? _width : 1);
}

void MyRectangle::Print() const
{
	for (int i = 0; i < coord.y; i++) {
		cout << endl;
	}	
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < coord.x; i++) {
			cout << ' ';
		}
		for (int i = 0; i <width; i++)
		{
			cout << symbol;
		}
		cout << endl;		
	}
	cout << "------------" << endl;
}

void MyRectangle::ChangeSize(float newWidth, float newHeight)
{
	height = (IsCorrectSize(newHeight) ? newHeight : 1);
	width = (IsCorrectSize(newWidth) ? newWidth : 1);
}

void MyRectangle::ChangeCoord(int dx, int dy)
{
	if (dx + coord.x >= 0 && dy+coord.y>=0) {
		coord.x += dx;
		coord.y += dy;
	}
	else {
		cout << "Error values of coordinates!" << endl;
	}	
}

void MyRectangle::SetSymbol(char _symbol)
{
	if (_symbol != ' ')
	{
		symbol = _symbol;
	}
}
