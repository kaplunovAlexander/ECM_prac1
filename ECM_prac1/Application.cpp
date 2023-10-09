#include "Application.h"
#include "Conversion.h"
#include <iostream>
#include <algorithm>

int TApplication::exec() {
	int key;
	while (true)
	{
		key = menu();
		switch (key)
		{
		case 1:
		{
			unsigned char data;
			std::cout << ">>";
			std::cin >> data;
			std::vector <int> binaryUChar = getBitsOfUChar(data);
			std::cout << "binary representation: ";
			for (int i = 0; i < sizeof(unsigned char) * 8; i++)
			{
				std::cout << binaryUChar[i];
			}
			sort(binaryUChar.begin(), binaryUChar.end(), std::greater<>());
			std::cout << "\nbinary representation for new number: "; 
			for (int i = 0; i < sizeof(unsigned char) * 8; i++)
			{
				std::cout << binaryUChar[i];
			}
			std::cout << '\n';
			fromBinaryToChar(binaryUChar);
			break;
		}
		case 2:
		{
			const std::string red("\033[0;31m");
			const std::string green("\033[0;32m");
			const std::string blue("\033[0;34m");
			std::string reset("\033[0m");
			double dataDouble;
			std::cout << ">>";
			std::cin >> dataDouble;
			std::vector <int> binaryDouble = getBitsOfDouble(dataDouble);
			std::cout << "binary representation: ";
			for (int i = 0; i < sizeof(double) * 8; i++)
			{
				if (i == 0) std::cout << blue << binaryDouble[i];
				else if (i > 0 && i < 12) std::cout << green << binaryDouble[i];
				else std::cout << red << binaryDouble[i];
			}
			std::cout << reset << "\nbinary representation for new number: ";
			sort(binaryDouble.begin(), binaryDouble.end());
			for (int i = 0; i < sizeof(double) * 8; i++)
			{
				if (i == 0) std::cout << blue << binaryDouble[i];
				else if (i > 0 && i < 12) std::cout << green << binaryDouble[i];
				else std::cout << red << binaryDouble[i];
			}
			std::cout << reset << '\n';
			fromBinaryToDouble(binaryDouble);
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
		{
			std::cout << "invalid value\n";
		}
		};
	}
}

int TApplication::menu() {
	int key;
	std::cout << "1. Get bits of unsigned char\n2. Get bits of double\n0. Quit the program\n>>";
	std::cin >> key;
	return key;
}