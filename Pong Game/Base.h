#pragma once
#include "MyLibraries.h"
#define ANCHO 100
#define ALTO 40

class Base
{

protected:
	int x, y;
	float dx, dy;
	int width, height;
	int points;
public:
	virtual int GetX() {
		return x;
	}
	virtual int GetY() {
		return y;
	}
	virtual int GetDX() {
		return dx;
	}
	virtual int GetDY() {
		return dy;
	}
	virtual int GetWidth() {
		return width;
	}
	virtual int GetHeight() {
		return height;
	}
	virtual void DeleteForm() {
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < height; j++)
			{

				Console::SetCursorPosition(x + i, y + j); cout << " ";
			}
		}
	}
	virtual void MoveForm() {

	}
	virtual void ShowForm() {

	}
	int FckngRandom(int ub, int lb) {
		return (rand() % (ub - lb) + 1) + lb;
	}
	virtual void SetPoints(int value) {
		points = value;
	}
	virtual int GetPoints() {
		return points;
	}
	virtual void SetDY(int value) {
		dy = value;
	}
	virtual void SetDX(int value) {
		dx = value;
	}
	virtual void SetX(int value) {
		x = value;
	}
	virtual void SetY(int value) {
		y = value;
	}
	virtual void ShowPoints() {

	}
};

