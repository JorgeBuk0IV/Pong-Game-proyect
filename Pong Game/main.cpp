#include "MyLibraries.h"
#include "GameManeger.h"
int main() {
	Console::CursorVisible = false;
	Console::SetWindowSize(ANCHO, ALTO);
	GameManeger* game;
	game = new GameManeger;
	game->ShowMainMenu();
	

	return 0;

} 