#pragma once
#include <vector>
#include "Cell.h"

namespace models
{
	class roulette
	{
	public:
		//Getters and Setters
		std::vector<cell> get_cells();

		std::size_t get_size();

		std::vector<cell> get_history();

		//Methods
		cell spin();


		//Constructors
		roulette();

	private:
		std::vector<cell> _cells; //This is the roulette
		std::size_t _size;
		std::vector<cell> _history;

		// Forming different types of roulette
		friend std::vector<cell> form_european();

		//Function for adding history
		void add_history(cell* last_cell);
	};
}
