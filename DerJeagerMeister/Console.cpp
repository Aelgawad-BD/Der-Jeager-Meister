#include "Console.h"

Console* Console::instance = 0;

Console::Console()
{

}

Console* Console::GetInstance()
{
	if (instance == 0)
	{
		instance = new Console();
	}
	return instance;
}

void Console::SetCursorPosition(int x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(hOut, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(hOut, &cursorInfo);
}

void Console::ClearScreen()
{
	system("cls");
}
