#pragma once
#include "Base.h"
class Ball :public Base
{
public:
	Ball() {
		width = 4;
		height = 1;
		x = Console::WindowWidth / 2 - width;
		y = Console::WindowHeight / 2 - height;
		dx = dy = 1;
		
	}
	void ShowForm() {
		Console::SetCursorPosition(x, y); cout << "•";
	}
	void MoveForm() {
		x += dx;
		y -= dy;
		if (y - height < Console::WindowTop || y + height > Console::WindowHeight)
		{
			dy *= -1;
		}
		if (x <= Console::WindowLeft || x + width >= Console::WindowWidth)
		{
			dx *= -1;
		}
	}

};

