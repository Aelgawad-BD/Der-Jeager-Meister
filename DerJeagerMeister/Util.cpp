#include "Util.h"

char* StringToCharArray(string input_str)
{
	int char_array_size = input_str.length() + 1;
	char* char_array = new char[char_array_size];
	// strcpy(char_array, input_str.c_str());
	strcpy_s(char_array, char_array_size, input_str.c_str());
	return char_array;
}