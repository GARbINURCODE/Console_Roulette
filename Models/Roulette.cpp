#include <iostream>
#include <fstream>
#include <vector>
#include "Roulette.h"

using namespace models;

// Getters and Setters
std::vector<cell> roulette::get_cells() { return(_cells); }

std::size_t roulette::get_size() { return(_size); }

std::vector<cell> roulette::get_history() { return(_history); }



//The functions that form different types of roulettes
std::vector<cell> form_european()
{
	std::vector<cell> cells;
	std::ifstream in;

	in.open("european.txt");

	if (in.is_open())
	{
		unsigned short counter = 0;
		unsigned number;

		while (in >> number)
		{
			cell new_cell = cell(number);

			new_cell.set_color('B');
			if (counter % 2 != 0) {
				new_cell.set_color('R');
			}

			counter++;
			cells.push_back(new_cell);
		}
		cells.front().set_color('G');
	}

	in.close();
	return(cells);
}

//Function for adding history
void roulette::add_history(cell* last_cell)
{
	auto iter = _history.cbegin();
	_history.emplace(iter, *last_cell);

	if (_history.size() > 10)
	{
		_history.pop_back();
	}
}


//Constructors
roulette::roulette()
{
	_cells = form_european();
	_size = _cells.size();
}



//Methods
cell roulette::spin()
{
	srand(time(NULL));
	auto& result = _cells[rand() % _size];

	this->add_history(&result);

	return result;
}
