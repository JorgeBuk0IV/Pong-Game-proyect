#pragma once
#include "Bar.h"
#include "SecondBar.h"
#include "Ball.h"
class GameManeger
{
private:
	Ball ball;
	SecondBar Sbar;
	Bar Fbar;

public:
	bool playing = true;
	GameManeger() {

	}
	~GameManeger() {

	}
	void RunGame() {
		while (playing)
		{
			Sbar.DeleteForm();
			Sbar.MoveForm();
			Sbar.ShowForm();
			Fbar.DeleteForm();
			Fbar.MoveForm();
			Fbar.ShowForm();
			ball.DeleteForm();
			ball.MoveForm();
			ball.ShowForm();
			Sbar.ShowPoints();
			Fbar.ShowPoints();
			if (CheckCollisionBarOne() || CheckCollisionBarTwo())
			{

				
				ball.SetDX(ball.GetDX() * -1);
			}
			CollisionExtremes();
			Win();
			

			
			_sleep(100);
		}
	}
	void Title() {
		int medioX = Console::WindowWidth / 2 ;
		int medioY = Console::WindowTop +5;
		
		    Console::SetCursorPosition(medioX - 35, medioY + 0); cout << "====================================================================";
			Console::SetCursorPosition(medioX - 35, medioY + 1); cout << " ____                                _____";
			Console::SetCursorPosition(medioX - 35, medioY + 2); cout << "|  _ \\  		                   /  ___|";
			Console::SetCursorPosition(medioX - 35, medioY + 3); cout << "| |_) | ___   _ __   __ _  	   | |  __   ____  _ __ __   ___";
			Console::SetCursorPosition(medioX - 35, medioY + 4); cout << "|  __/ / _ \\ | '_ \\ / _` | 	   | | |  | / _` | | '_\\_ \\ / _ \\";
			Console::SetCursorPosition(medioX - 35, medioY + 5); cout << "| |   | (_) || | | | (_| | 	   | |__| || (_| | | | | | |  __/";
			Console::SetCursorPosition(medioX - 35, medioY + 6); cout << "|_|    \\___/ |_| |_|\\__, |	   \\______|\\__,_|| |_| | |_|\\___|";
			Console::SetCursorPosition(medioX - 35, medioY + 7); cout << "	                    |___/";
			Console::SetCursorPosition(medioX - 35, medioY + 8); cout << "====================================================================";
			Console::SetCursorPosition(medioX - 35, medioY + 9); cout << "\n";
			Console::SetCursorPosition(medioX - 35, medioY + 10); cout << "\n";
			Console::SetCursorPosition(medioX - 35, medioY + 11); cout << "\n";
			Console::SetCursorPosition(medioX - 35, medioY + 12); cout << "-------------------------------MENU-------------------------------" << endl;
			Console::SetCursorPosition(medioX - 35, medioY + 14); cout << "                            1) Play" << endl;
			Console::SetCursorPosition(medioX - 35, medioY + 15); cout << "                            2) Credits" << endl;
			Console::SetCursorPosition(medioX - 35, medioY + 16 ); cout << "                            3) Exit" << endl;
			Console::SetCursorPosition(medioX - 35, medioY +  17); cout << "Press any key... ";
	}					
	void ShowCredits() {
		int medioX = Console::WindowLeft;
		int medioY = Console::WindowHeight + 2;
		Console::SetCursorPosition(medioX , medioY + 0); cout << "Main Developer/Creator : Jorge Luis Torres Bukvich" << endl;
		Console::SetCursorPosition(medioX , medioY + 1); cout << "Press any key to go back to menu.." << endl;
		getch();
	}
	void ShowMainMenu() {
		int opcion = 0;
		bool menuActivo = true;
	

		while (menuActivo) {
			system("cls");
			Title();

			opcion = getch();

			switch (opcion) {
			case '1':
				system("cls");
				RunGame();
				break;
			case '2':
				system("cls");
				ShowCredits();
				break;
			case '3':
				menuActivo = false;
				break;
			default:
				system("cls");
				Console::SetCursorPosition(Console::WindowLeft, Console::WindowHeight + 16); cout << "No valid option, try again!" << endl;
				Console::SetCursorPosition(Console::WindowLeft, Console::WindowHeight + 17); cout << "Press any key to go back to menu.." << endl;
				getch();
				break;
			}
		}
	}
	bool CheckCollisionBarOne() {

		int paddleLeft = Fbar.GetX();
		int paddleRight = Fbar.GetX() + Fbar.GetWidth();
		int paddleTop = Fbar.GetY();
		int paddleBottom = Fbar.GetY() + Fbar.GetHeight();
		int ballLeft = ball.GetX();
		int ballRight = ball.GetX() + ball.GetWidth();
		int ballTop = ball.GetY();
		int ballBottom = ball.GetY() + ball.GetHeight();
		if (ballLeft >= paddleRight)
		{
			return false;
		}

		if (ballRight <= paddleLeft)
		{
			return false;
		}

		if (ballTop >= paddleBottom)
		{
			return false;
		}

		if (ballBottom <= paddleTop)
		{
			return false;
		}

		return true;
		


	}
	bool CheckCollisionBarTwo() {
		int paddleLeft = Sbar.GetX();
		int paddleRight = Sbar.GetX() + Sbar.GetWidth();
		int paddleTop = Sbar.GetY();
		int paddleBottom = Sbar.GetY() + Sbar.GetHeight();
		int ballLeft = ball.GetX();
		int ballRight = ball.GetX() + ball.GetWidth();
		int ballTop = ball.GetY();
		int ballBottom = ball.GetY() + ball.GetHeight();
		if (ballLeft >= paddleRight)
		{
			return false;
		}

		if (ballRight <= paddleLeft)
		{
			return false;
		}

		if (ballTop >= paddleBottom)
		{
			return false;
		}

		if (ballBottom <= paddleTop)
		{
			return false;
		}

		return true;
	}
	void CollisionExtremes() {
		
		if (ball.GetX() + ball.GetWidth() >= Console::WindowWidth)
		{
			ball.DeleteForm();
			ball.SetX(Console::WindowWidth / 2 - ball.GetWidth());
			ball.SetY(Console::WindowHeight / 2 - ball.GetHeight());
			ball.DeleteForm();
			Fbar.SetPoints(Fbar.GetPoints() + 1);
		}
		if (ball.GetX() <= Console::WindowLeft )
		{
			ball.DeleteForm();
			ball.SetX(Console::WindowWidth / 2 - ball.GetWidth());
			ball.SetY(Console::WindowHeight / 2 - ball.GetHeight());
			ball.DeleteForm();	
			
			Sbar.SetPoints(Sbar.GetPoints() + 1);
		}

		
	}
		
	void Win() {
		if (Fbar.GetPoints() == 5 )
		{
			system("cls");
			// Código para mostrar "WIN" en el centro de la pantalla
			Console::SetCursorPosition((ANCHO / 2) - 10, (ALTO / 2));    cout << "  WW         WW  IIIII  NN     NN" << endl;
			Console::SetCursorPosition((ANCHO / 2) - 10, (ALTO / 2) + 1);cout << "  WW    W    WW   III   NNNN   NN" << endl;
			Console::SetCursorPosition((ANCHO / 2) - 10, (ALTO / 2) + 2);cout << "   WW  W W  WW    III   NN NN  NN" << endl;
			Console::SetCursorPosition((ANCHO / 2) - 10, (ALTO / 2) + 3);cout << "    WW W W WW     III   NN  NN NN" << endl;
			Console::SetCursorPosition((ANCHO / 2) - 10, (ALTO / 2) + 4);cout << "     WW   WW     IIIII  NN   NNNN" << endl;

			getch();
			system("cls");
			playing = false;
		}
		else if (Sbar.GetPoints() == 5)
		{
			system("cls");
			Console::SetCursorPosition((ANCHO / 2 )- 10, (ALTO / 2));     cout << "  GGG     A    M   M  EEEEE      OOO   V   V  EEEEE  RRRR " << endl;
			Console::SetCursorPosition((ANCHO / 2) - 10, (ALTO / 2) + 1); cout << " G       A A   MM MM  E         O   O  V   V  E      R   R" << endl;
			Console::SetCursorPosition((ANCHO / 2) - 10, (ALTO / 2) + 2); cout << " G  GG  AAAAA  M M M  EEE       O   O   V V   EEE    RRRR " << endl;
			Console::SetCursorPosition((ANCHO / 2) - 10, (ALTO / 2) + 3); cout << " G   G A     A M   M  E         O   O    V    E      R  R" << endl;
			Console::SetCursorPosition((ANCHO / 2) - 10, (ALTO / 2) + 4); cout << "  GGG  A     A M   M  EEEEE      OOO     V    EEEEE  R   R" << endl;
			getch();
			system("cls");
			playing = false;
		}
		

		
}	
	

	
};

 






















 
 
 
 



  








 
 
 
    














