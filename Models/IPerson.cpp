#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "IPerson.h"
#include "Person.h"

using namespace models;
using namespace controllers;

//CRUD Methods
bool IPerson::Create(std::string* name, std::string* password)
{
	std::ifstream in;
	in.open("persons.txt");

	std::string input_string;
	std::string exist_name;

	while (std::getline(in, input_string))
	{
		std::stringstream flow(input_string);

		flow >> exist_name;

		if (*name == exist_name)
		{
			return(false);
		}
	}
	Person user;
	user = Person(name, password);

	in.close();

	std::ofstream out;
	out.open("persons.txt", std::ios::app);

	out << std::left << std::setw(20) << user.name();
	out << std::left << std::setw(20) << user.password();
	out << std::left << std::setw(20) << user.balance() << std::endl;

	out.flush();
	out.close();

	return(true);
}

Person IPerson::Read(std::string name) 
{ 
	std::string s;
	std::ifstream in;

	in.open("persons.txt");


	while (std::getline(in, s))
	{
		std::stringstream flow(s);

		std::string input_name;
		std::string input_password;
		unsigned balance;

		flow >> input_name >> input_password >> balance;

		if ((name == input_name))
		{
			in.close();

			return (Person(input_name, input_password, balance));
		}
	}
	return(Person());

}

void IPerson::Update(Person* user)
{ 
	std::vector<Person> persons_copy;
	std::ifstream in;
	std::ofstream out;

	std::string in_string;

	std::string name;
	std::string password;
	unsigned balance;

	in.open("persons.txt");

	while (std::getline(in, in_string))
	{
		std::stringstream flow(in_string);
		flow >> name >> password >> balance;

		if (name == user->name()) { continue; }

		persons_copy.push_back(Person(name, password, balance));
	}
	in.close();

	out.open("persons.txt");


	for (Person person : persons_copy)
	{
		out << std::left << std::setw(20) << person.name();
		out << std::left << std::setw(20) << person.password();
		out << std::left << std::setw(20) << person.balance() << std::endl;
	}
	out << std::left << std::setw(20) << user->name();
	out << std::left << std::setw(20) << user->password();
	out << std::left << std::setw(20) << user->balance() << std::endl;


	out.flush();
	out.close();
}

void IPerson::Delete(Person* user) 
{ 
	std::vector<Person> persons_copy;
	std::ifstream in;
	std::ofstream out;

	std::string in_string;

	std::string name;
	std::string password;
	unsigned balance;

	in.open("persons.txt");

	while (std::getline(in, in_string))
	{
		std::stringstream flow(in_string);
		flow >> name >> password >> balance;

		if (name == user->name()) { continue; }

		persons_copy.push_back(Person(name, password, balance));
	}
	in.close();

	out.open("persons.txt");


	for (Person person : persons_copy)
	{
		out << std::left << std::setw(20) << person.name();
		out << std::left << std::setw(20) << person.password();
		out << std::left << std::setw(20) << person.balance() << std::endl;
	}

	out.flush();
	out.close();
}


//Constructors
IPerson::IPerson() {}