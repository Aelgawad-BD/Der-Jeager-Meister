#pragma once
#include <Windows.h>
#include <iostream>

class Console
{
	// SINGELTON
public:
	static Console* GetInstance();
	void SetCursorPosition(int, int);
	void ClearScreen();

private:
	Console();
	static Console* instance;
};