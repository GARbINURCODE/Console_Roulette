#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Menu.h"
#include "IPerson.h"
#include "Person.h"

using namespace view;
using namespace controllers;
using namespace models;

//Methods
int Menu::Welcome()
{
	while (true)
	{
		char k;

		std::cout << "Hello, dear guest! Are you new here?\n" <<
			"1.Sing up\n" << "2.Log in\n" << "Q.Quit\n" << std::endl;
		std::cin >> k;

		switch (k)
		{
		case '1':
			system("cls");
			this->Sign_Up();
		case '2':
		{
			system("cls");

			Person user = this->Log_In();

			if (user.name() != "")
			{
				this->Choose_Game(&user);
			}

			break;
		}
		case 'Q':
			return 0;
			break;
		default:
			system("cls");
			std::cout << "The wrong number!! Try one more time.\n" << std::endl;
			break;
		}
	}
}

void Menu::Sign_Up()
{
	while (true)
	{
		std::string name;
		std::string password;
		std::string password_repeat;

		std::cout << "Insert the username:\n";
		std::cin >> name;

		std::cout << "Insert the password:\n";
		std::cin >> password;

		std::cout << "Repeat the password:\n";
		std::cin >> password_repeat;

		if (password == password_repeat)
		{
			if (iperson.Create(&name, &password))
			{
				std::cout << "Sign up comleted successful!\n";
				break;
			}
		}

		std::cout << "Something went wrong! Try one more time.\n";
		continue;

	}
}

Person view::Menu::Log_In()
{
	while (true)
	{
		std::string name;
		std::string password;

		std::cout << "Please, log in or input Q to quit\n";

		std::cout << "Insert the username:\n";
		std::cin >> name;

		std::cout << "Insert the password:\n";
		std::cin >> password;

		if (name == "Q" || password == "Q") { system("cls");  return Person(); }

		Person user = iperson.Read(name);

		if (name == user.name() && password == user.password())
		{
			system("cls");
			std::cout << "Hello, " << name << std::endl;

			return user;
		}

		std::cout << "Password or username is wrong! Try one more time.\n";
	}

}

int Menu::Choose_Game(Person* user)
{
	char k;

	while (true)
	{
		std::cout << "Choose the game:\n" << "1.Roulette\n" << 
			"Q.Quit\n" << std::endl;
		std::cin >> k;

		switch (k)
		{
		case '1':
			system("cls");
			if (this->Roulette(user) == 1)
			{
				return 0;
			};
			break;
		case 'Q':
			system("cls");
			return 0;
			break;
		default:
			system("cls");
			std::cout << "The wrong number!! Try one more time.\n" << std::endl;
			break;
		}
	}
}

int view::Menu::Roulette(models::Person* user)
{
	char k;
	roulette roulette;

	while (true)
	{
		if (user->balance() == 0) { iperson.Delete(user); return 1; }

		std::cout << "Balance: " << user->balance() << "\n";
		std::cout << "Bet: " << user->bet_money() << "\n";

		std::cout << "R - Red, B - Black\n" << "History: ";

		for (cell cell : roulette.get_history())
		{
			std::cout << cell.get_number() << " " << cell.get_color() << ", ";
		}

		this->Show_Field();

		std::cout << "\n\nPlace a bet:\n" <<
			"1.Red or Black 1:1 " << user->bet_money('C') << " points " << "Bet: " << ibet.Read_Bet(user, 'C').display() << "\n" <<
			"2.Odd or Even 1:1 " << user->bet_money('E') << " points " << "Bet: " << ibet.Read_Bet(user, 'E').display() << "\n" <<
			"3.Big(> 18) or Small(<18) 1:1 " << user->bet_money('S') << " points " << "Bet: " << ibet.Read_Bet(user, 'S').display() << "\n" <<
			"4.Dozen 2:1 " << user->bet_money('D') << " points " << "Bet: " << ibet.Read_Bet(user, 'D').display() << "\n" <<
			"5.Column 2:1 " << user->bet_money('c') << " points " << "Bet: " << ibet.Read_Bet(user, 'c').display() << "\n" <<
			"6.Street 11:1 " << user->bet_money('s') << " points " << "Bet: " << ibet.Read_Bet(user, 's').display() << "\n" <<
			"7.Number 35:1 " << user->bet_money('N') << " points " << "Bet: " << ibet.Read_Bet(user, 'N').display() << "\n" <<
			"D.Delete bet\n" <<
			"S.Spin\n" << 
			"Q.Quit\n" << std::endl;

		std::cin >> k;

		switch (k)
		{
		case '1':
			this->Color_Bet(user);
			break;
		case '2':
			this->Evenness_Bet(user);
			break;
		case '3':
			this->Size_Bet(user);
			break;
		case '4':
			this->Dozen_Bet(user);
			break;
		case '5':
			this->Column_Bet(user);
			break;
		case '6':
			this->Street_Bet(user);
			break;
		case '7':
			this->Number_Bet(user);
			break;
		case 'D':
			this->Delete_Bet(user);
			system("cls");
			break;
		case 'S':
			system("cls");

			switch (ibet.Check_Bets(user, &roulette))
			{
			case 0:
				std::cout << "You lost:(\n\n";
				break;
			case 1:
				std::cout << "You won!\n\n";
				break;
			case 2:
				std::cout << "It is too big amount for you!\n\n"; 
				break;
			}
			break;
		case 'Q':
			system("cls");
			iperson.Update(user);
			return 0;
			break;
		default:
			system("cls");
			std::cout << "The wrong number!! Try one more time.\n" << std::endl;
			break;
		}
	}
}

//Bets Menus
int view::Menu::Color_Bet(models::Person* user)
{
	char color;
	unsigned money;

	system("cls");
	while (true)
	{
		std::cout << "Insert the color(R/B):\n";
		std::cin >> color;

		if (color != 'R' && color != 'B') { system("cls");  std::cout << "Try one more time!\n\n"; continue; }
		if (color == 'Q') { return 0; }

		std::cout << "Insert the amount of money:\n";
		std::cin >> money;

		ibet.Add_Collor_Bet(user, color, money);
		system("cls");
		break;
	}
	return 1;
}

int view::Menu::Evenness_Bet(models::Person* user)
{
	char input;
	unsigned money;

	system("cls");
	while (true)
	{
		std::cout << "Insert the eveness(O/E):\n";
		std::cin >> input;

		if (input != 'E' && input != 'O') { system("cls");  std::cout << "Try one more time!\n\n"; continue; }
		if (input == 'Q') { return 0; }

		std::cout << "Insert the amount of money:\n";
		std::cin >> money;

		ibet.Add_Evenness_Bet(user, (input == 'E'), money);
		system("cls");
		break;
	}
	return 1;
}

int view::Menu::Size_Bet(models::Person* user)
{
	char input;
	unsigned money;

	system("cls");
	while (true)
	{
		std::cout << "Insert if the number is going to be big or small number(B/S):\n";
		std::cin >> input;

		if (input != 'B' && input != 'S') { system("cls");  std::cout << "Try one more time!\n\n"; continue; }
		if (input == 'Q') { return 0; }

		std::cout << "Insert the amount of money:\n";
		std::cin >> money;

		ibet.Add_Size_Bet(user, (input == 'S'), money);
		system("cls");
		break;
	}
	return 1;
}

int view::Menu::Dozen_Bet(models::Person* user)
{
	unsigned short input;
	unsigned money;

	system("cls");
	while (true)
	{
		std::cout << "Insert if the number of dozen(1: 1-12 2: 13-24 3: 25-36):\n";
		std::cin >> input;

		if ((input != 1 && input != 2) && input != 3) { system("cls");  std::cout << "Try one more time!\n\n"; continue; }

		std::cout << "Insert the amount of money:\n";
		std::cin >> money;

		ibet.Add_Dozen_Bet(user, input, money);
		system("cls");
		break;
	}
	return 1;
}

int view::Menu::Column_Bet(models::Person* user)
{
	unsigned short input;
	unsigned money;

	system("cls");
	while (true)
	{
		std::cout << "Insert if the number of column(1-3):\n";
		std::cin >> input;

		if ((input != 1 && input != 2) && input != 3) { system("cls");  std::cout << "Try one more time!\n\n"; continue; }

		std::cout << "Insert the amount of money:\n";
		std::cin >> money;

		ibet.Add_Column_Bet(user, input, money);
		system("cls");
		break;
	}
	return 1;
}

int view::Menu::Street_Bet(models::Person* user)
{
	int input;
	unsigned money;

	system("cls");
	while (true)
	{
		std::cout << "Insert if the number of street(1-12):\n";
		std::cin >> input;

		if (input <= 0 || input > 12) { system("cls");  std::cout << "Try one more time!\n\n"; continue; }

		std::cout << "Insert the amount of money:\n";
		std::cin >> money;

		ibet.Add_Street_Bet(user, input, money);
		system("cls");
		break;
	}
	return 1;
}

int view::Menu::Number_Bet(models::Person* user)
{
	int input;
	unsigned money;

	system("cls");
	while (true)
	{
		std::cout << "Insert if the number of the cell(0-36):\n";
		std::cin >> input;

		if (input < 0 || input > 36) { system("cls");  std::cout << "Try one more time!\n\n"; continue; }

		std::cout << "Insert the amount of money:\n";
		std::cin >> money;

		ibet.Add_Number_Bet(user, input, money);
		system("cls");
		break;
	}
	return 1;
}

int view::Menu::Delete_Bet(models::Person* user)
{
	char input;
	char k;

	while (true)
	{
		system("cls");
		std::cout << "Choose a bet or insert Q to Quit:\n" <<
			"1.Red or Black\n" <<
			"2.Odd or Even\n" <<
			"3.Big(> 18) or Small(<18)\n" <<
			"4.Dozen\n" <<
			"5.Column\n" <<
			"6.Street\n" <<
			"7.Number\n" <<
			"Q.Quit\n" << std::endl;

		std::cin >> input;

		switch (input)
		{
		case '1': k = 'C'; break;
		case '2': k = 'E'; break;
		case '3': k = 'S'; break;
		case '4': k = 'D'; break;
		case '5': k = 'c'; break;
		case '6': k = 's'; break;
		case '7': k = 'N'; break;
		case 'Q':
			system("cls");
			return 0;
			break;
		default:
			system("cls");
			k = 'z';
			std::cout << "The wrong input!! Try one more time.\n" << std::endl;
			break;
		}

		if (k != 'z') { ibet.Delete_Bet(user, k); return 0; }
	}
	
}

void view::Menu::Show_Field()
{
	std::cout << "\n";

	std::string s;
	std::ifstream in;

	in.open("field.txt");


	while (std::getline(in, s))
	{
		std::cout << s << "\n";
	}

	in.close();
}

//Constructor
Menu::Menu() 
{ 
	IPerson iperson = IPerson();
	IBet ibet = IBet();
}