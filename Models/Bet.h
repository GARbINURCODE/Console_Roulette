#pragma once
#include <iostream>
#include <vector>
#include "Cell.h"
#include "Roulette.h"

namespace models
{
	class Bet
	{
	public:
		//Getters and Setters
		std::vector<cell> numbers();
		void numbers(std::vector<cell> numbers);

		unsigned short multiplier();
		void multiplier(unsigned short multiplier);

		unsigned money();
		void money(unsigned money);

		bool isWork(cell cell);
		bool isWork();
		void isWork(bool isWork);

		char type();
		void type(char type);

		std::string display();
		void display(std::string display);

		//Constructors
		Bet();


	private:
		std::vector<cell> _numbers;
		unsigned short _multiplier;
		unsigned _money;
		bool _isWork;
		char _type;
		std::string _display;
	};
}
