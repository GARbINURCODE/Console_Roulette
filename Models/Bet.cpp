#include "Bet.h"
#include "Cell.h"
#include "Roulette.h"

using namespace models;

//Getters and Setters
std::vector<cell> Bet::numbers() { return(_numbers); }
void Bet::numbers(std::vector<cell> numbers) { _numbers = numbers; }

unsigned short Bet::multiplier() { return(_multiplier); }
void Bet::multiplier(unsigned short multiplier) { _multiplier = multiplier; }

unsigned Bet::money() { return(_money); }
void Bet::money(unsigned money) { _money = money; }

bool Bet::isWork(cell Cell)
{
	for (cell bet_cell : _numbers)
	{
		if (bet_cell == Cell)
		{
			_money = _money * _multiplier;
			_isWork = true;
			break;
		}
	}
	return(_isWork);
}
bool Bet::isWork() { return(_isWork); }
void Bet::isWork(bool isWork) { _isWork = isWork; }

char Bet::type() { return(_type); }
void Bet::type(char type) { _type = type; }

std::string Bet::display() { return(_display); }
void Bet::display(std::string display) { _display = display; }
 

//Constructors
Bet::Bet()
{
	_multiplier = 1;
	_money = 0;
	_isWork = false;
	_type = ' ';
	_display = "-";

}