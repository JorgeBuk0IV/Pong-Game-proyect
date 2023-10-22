#pragma once
#include "Base.h"
class SecondBar :public Base
{
public:
	SecondBar() {
		width = 4;
		height = 12;
		x = Console::WindowWidth - width -2;
		y = Console::WindowHeight / 2 - height;
		dx = dy = 2;
		points = 0;
	}
	void ShowForm() {
		for (int i = 0; i < height; i++) {
			Console::SetCursorPosition(x, y + i);
			cout << "|0|";
		}
	}
	void MoveForm() {

		y -= dy;
		if (y < Console::WindowTop)
		{
			dy *= -1;
			y = Console::WindowTop;

		}
		if (y + height > Console::WindowHeight) {
			dy *= -1;
			y = Console::WindowHeight - height;
		}
		
			
			
		}
	void ShowPoints() {
		Console::SetCursorPosition(65, Console::WindowTop);
		cout << "Points :" << GetPoints() << " ";
	}

};

