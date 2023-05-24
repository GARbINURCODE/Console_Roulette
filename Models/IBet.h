#pragma once
#include "Bet.h"
#include "Person.h"

namespace controllers 
{
	class IBet
	{
	public:
		//Methods
		void Add_Collor_Bet(models::Person* user, char color, unsigned money);
		void Add_Evenness_Bet(models::Person* user, bool attribute, unsigned money);
		void Add_Size_Bet(models::Person* user, bool attribute, unsigned money);
		void Add_Dozen_Bet(models::Person* user, unsigned attribute, unsigned money);
		void Add_Column_Bet(models::Person* user, unsigned attribute, unsigned money);
		void Add_Street_Bet(models::Person* user, unsigned attribute, unsigned money);
		void Add_Number_Bet(models::Person* user, unsigned attribute, unsigned money);

		int Check_Bets(models::Person* user, models::roulette* roulette);

		void Delete_Bet(models::Person* user, char type);

		models::Bet Read_Bet(models::Person* user, char type);

		//Constructors
		IBet();
	};

}

