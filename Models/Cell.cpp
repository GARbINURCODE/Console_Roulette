#include "Cell.h"

using namespace models;

//Getters and setters
unsigned short cell::get_number() { return(_number); }
void cell::set_number(unsigned char number) { _number = number; }

char cell::get_color() { return(_color); }
void cell::set_color(char color) { _color = color; }

bool cell::get_isEven() { return(_isEven); }

bool cell::get_isSmall() { return(_isSmall); }

unsigned char cell::get_dozen() { return(_dozen); }

unsigned char cell::get_column() { return(_column); }


unsigned char cell::get_street() { return(_street); }


//Constructors
cell::cell()
{
	_number = 0;
	_color = 'N';
	_isEven = 0;
	_isSmall = 0;
	_dozen = 0;
	_column = 0;
	_street = 0;
}

cell::cell(unsigned char number)
{
	_number = number;
	_color = 'N';
	_isEven = (_number % 2 == 0);
	_isSmall = (_number <= 18 && _number != 0);
	_dozen = (_number - 1) / 12 + 1;

	_column = _number % 3;
	if (_column == 0) {
		_column = 3;
	}

	_street = _number / 3 + 1;
}

//Operators
bool cell::operator==(cell Cell)
{
	if (cell::get_number() == Cell.get_number())
	{
		return(true);
	}
	return(false);
}

bool cell::operator==(int num)
{
	if (cell::get_number() == num) { return(true); }
	return(false);
}

bool cell::operator!=(int num)
{
	if (cell::get_number() != num) { return(true); }
	return(false);
}