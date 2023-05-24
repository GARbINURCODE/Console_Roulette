#pragma once
#include "IPerson.h"
#include "IBet.h"
#include "Person.h"

namespace view
{
	class Menu
	{
	private:
		controllers::IPerson iperson;
		controllers::IBet ibet;
	public:
		//Methods
		int Welcome();
		void Sign_Up();
		models::Person Log_In();
		int Choose_Game(models::Person* user);
		int Roulette(models::Person* user);

		//Bet Menuse
		int Color_Bet(models::Person* user);
		int Evenness_Bet(models::Person* user);
		int Size_Bet(models::Person* user);
		int Dozen_Bet(models::Person* user);
		int Column_Bet(models::Person* user);
		int Street_Bet(models::Person* user);
		int Number_Bet(models::Person* user);

		int Delete_Bet(models::Person* user);

		void Show_Field();

		//Constructor
		Menu();
	};
}


