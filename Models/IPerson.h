#pragma once
#include <iostream>
#include "Person.h"

namespace controllers
{
	class IPerson
	{

	public:
		//CRUD Methods
		bool Create(std::string* name, std::string* password);
		models::Person Read(std::string name);
		void Update(models::Person* user);
		void Delete(models::Person* user);

		//Constructor
		IPerson();
	};
}
