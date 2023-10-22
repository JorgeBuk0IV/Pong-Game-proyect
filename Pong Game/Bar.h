#pragma once
#include "Base.h"
class Bar :public Base
{
public:
	Bar() {
		width = 4;
		height = 12;
		x = 3;
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
	void MoveForm(){
		if (_kbhit())
		{
			char tecla = toupper(getch());
			if (tecla == 'W' && y - dx > Console::WindowTop) {
				y -= dy;
				if (y - dy - 1< Console::WindowTop) {
					y = Console::WindowTop;
				}
			}
			if (tecla == 'S' && y + dx + height < Console::WindowHeight) {
				y += dy;
				if (y + dy + height + 1> Console::WindowHeight)
				{
					y =Console::WindowHeight - height;
				}
			}
		}
	
	}
	void ShowPoints() {
		Console::SetCursorPosition(20, Console::WindowTop);
		cout <<"Points :"<< GetPoints() <<" ";
	}
};

