#pragma once
#include <iostream>
#include "Bet.h"

namespace models
{
	class Person
	{
	public:
		//Getters and setters
		std::string name();
		void name(std::string name);

		std::string password();
		void password(std::string password);

		unsigned int balance();
		void balance(unsigned int balance);

		std::vector<Bet> bets();
		void bets(std::vector<Bet> bets);

		//Constructors
		Person();
		Person(std::string* name, std::string* password);
		Person(std::string name, std::string password, unsigned balance);

		//Methods
		void add_bet(Bet bet);
		unsigned bet_money(char type);
		unsigned bet_money();

	private:
		std::string _name;
		std::string _password;
		unsigned int _balance;
		std::vector<Bet> _bets;
	};
}
