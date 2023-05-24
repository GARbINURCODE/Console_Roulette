#pragma once

namespace models
{
	class cell
	{
	public:
		//Getters and setters
		unsigned short get_number();
		void set_number(unsigned char number);

		char get_color();
		void set_color(char color);

		bool get_isEven();

		bool get_isSmall();

		unsigned char get_dozen();

		unsigned char get_column();

		unsigned char get_street();

		//Constructors
		cell();
		cell(unsigned char number);

		//Operators
		bool operator==(cell Cell);
		bool operator==(int num);
		bool operator!=(int num);

	private:
		unsigned short _number; //Number of the cell
		char _color; // Collor of the cell
		bool _isEven; // True: Even and False: Odd
		bool _isSmall; // True: Number is less than 18
		unsigned char _dozen; // 1: 1-12 2: 13-24 3: 25-36 
		unsigned char _column; // (num - column) % 3 = 0 vertical line
		unsigned char _street; // street = (num / 3) + 1 horizontal line
	};
}
