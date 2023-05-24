#include <vector>
#include "IBet.h"
#include "Bet.h"
#include "Roulette.h"
#include <sstream>
#include <string>

using namespace controllers;
using namespace models;

void controllers::IBet::Add_Collor_Bet(Person* user, char color, unsigned money)
{
	roulette roulette;
	Bet bet;
	std::vector<cell> numbers;

	if (color == 'R') { bet.display("Red"); }
	else { bet.display("Black"); }

	for (cell cell : roulette.get_cells())
	{
		if (cell.get_color() == color)
		{
			numbers.push_back(cell);
		}
	}
	bet.numbers(numbers);

	bet.multiplier(2);
	bet.money(money);
	bet.isWork(false);
	bet.type('C');

	user->add_bet(bet);
}

void controllers::IBet::Add_Evenness_Bet(models::Person* user, bool attribute, unsigned money)
{
	roulette roulette;
	Bet bet;
	std::vector<cell> numbers;

	if (attribute = true) { bet.display("Even"); }
	else { bet.display("Odd"); }

	for (cell cell : roulette.get_cells())
	{
		if (cell.get_isEven() == attribute && cell != 0)
		{
			numbers.push_back(cell);
		}
	}
	bet.numbers(numbers);

	bet.multiplier(2);
	bet.money(money);
	bet.isWork(false);
	bet.type('E');

	user->add_bet(bet);
}

void controllers::IBet::Add_Size_Bet(models::Person* user, bool attribute, unsigned money)
{
	roulette roulette;
	Bet bet;
	std::vector<cell> numbers;

	if (attribute = true) { bet.display("Small"); }
	else { bet.display("Big"); }

	for (cell cell : roulette.get_cells())
	{
		if (cell.get_isSmall() == attribute && cell != 0)
		{
			numbers.push_back(cell);
		}
	}
	bet.numbers(numbers);

	bet.multiplier(2);
	bet.money(money);
	bet.isWork(false);
	bet.type('S');

	user->add_bet(bet);
}

void controllers::IBet::Add_Dozen_Bet(models::Person* user, unsigned attribute, unsigned money)
{
	roulette roulette;
	Bet bet;
	std::vector<cell> numbers;

	bet.display(std::to_string(attribute));

	for (cell cell : roulette.get_cells())
	{
		if (cell.get_dozen() == attribute && cell != 0) 
		{
			numbers.push_back(cell);
		}
	}
	bet.numbers(numbers);

	bet.multiplier(3);
	bet.money(money);
	bet.isWork(false);
	bet.type('D');

	user->add_bet(bet);
}

void controllers::IBet::Add_Column_Bet(models::Person* user, unsigned attribute, unsigned money)
{
	roulette roulette;
	Bet bet;
	std::vector<cell> numbers;

	bet.display(std::to_string(attribute));

	for (cell cell : roulette.get_cells())
	{
		if (cell.get_column() == attribute && cell != 0)
		{
			numbers.push_back(cell);
		}
	}
	bet.numbers(numbers);

	bet.multiplier(3);
	bet.money(money);
	bet.isWork(false);
	bet.type('c');

	user->add_bet(bet);
}

void controllers::IBet::Add_Street_Bet(models::Person* user, unsigned attribute, unsigned money)
{
	roulette roulette;
	Bet bet;
	std::vector<cell> numbers;

	bet.display(std::to_string(attribute));

	for (cell cell : roulette.get_cells())
	{
		if (cell.get_street() == attribute && cell != 0)
		{
			numbers.push_back(cell);
		}
	}
	bet.numbers(numbers);

	bet.multiplier(12);
	bet.money(money);
	bet.isWork(false);
	bet.type('s');

	user->add_bet(bet);
}

void controllers::IBet::Add_Number_Bet(models::Person* user, unsigned attribute, unsigned money)
{
	roulette roulette;
	Bet bet;
	std::vector<cell> numbers;

	bet.display(std::to_string(attribute));

	for (cell cell : roulette.get_cells())
	{
		if (cell.get_number() == attribute)
		{
			numbers.push_back(cell);
			break;
		}
	}
	bet.numbers(numbers);

	bet.multiplier(36);
	bet.money(money);
	bet.isWork(false);
	bet.type('N');

	user->add_bet(bet);
}

int controllers::IBet::Check_Bets(Person* user, roulette* roulette)
{
	unsigned sum = 0;
	unsigned short res = 0;

	cell result = roulette->spin();

	for (Bet bet : user->bets())
	{
		sum += bet.money();
	}
	if (sum > user->balance()) { return 2; }

	for (Bet bet : user->bets())
	{
		user->balance(user->balance() - bet.money());
		if (bet.isWork(result))
		{
			user->balance(user->balance() + bet.money());
			res = 1;
		}
	}

	return res;
}

void controllers::IBet::Delete_Bet(models::Person* user, char type)
{
	std::vector<Bet> bets = user->bets();

	auto iter = bets.cbegin();

	while(iter != bets.cend())
	{
		Bet bet = *iter;

		if (bet.type() == type)
		{
			bets.erase(iter);
			break;
		}
		++iter;
	}

	user->bets(bets);
}

models::Bet controllers::IBet::Read_Bet(models::Person* user, char type)
{
	for (Bet bet : user->bets())
	{
		if (bet.type() == type)
		{
			return(bet);
		}
	}

	return(Bet());
}

//Constructors
IBet::IBet() {}