#include <fstream>
#include <iomanip>
#include <vector>
#include "Person.h"
#include "Bet.h"

using namespace models;

//Getters and setters
std::string Person::name() { return(_name); }
void Person::name(std::string name) { _name = name; }

std::string Person::password() { return(_password); }
void Person::password(std::string password) { _password = password; }

unsigned int Person::balance() { return(_balance); }
void Person::balance(unsigned int balance) { _balance = balance; }

std::vector<Bet> Person::bets()
{
	return(_bets);
}
void Person::bets(std::vector<Bet> bets) { _bets = bets; }


//Constructors
Person::Person()
{
	std::vector<Bet> bets;

	_name = "";
	_password = "";
	_balance = 0;
	_bets = bets;
}

Person::Person(std::string* name, std::string* password)
{
	std::vector<Bet> bets;

	_name = *name;
	_password = *password;
	_balance = 1000;
	_bets = bets;
}

Person::Person(std::string name, std::string password, unsigned balance)
{
	_name = name;
	_password = password;
	_balance = balance;
	std::vector<Bet> _bets;
}

//Methods
void Person::add_bet(Bet bet)
{
	_bets.push_back(bet);
}

unsigned Person::bet_money(char type)
{
	for (Bet bet : this->_bets)
	{
		if (type == bet.type()) { return(bet.money()); }
	}
	return(0);
}

unsigned models::Person::bet_money()
{
	unsigned result = 0;

	for (Bet bet : this->_bets)
	{
		result += bet.money();
	}

	return(result);
}