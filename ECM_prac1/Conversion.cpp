#include "Conversion.h"
#include <vector>

const std::string red("\033[0;31m");
const std::string green("\033[0;32m");
const std::string blue("\033[0;34m");
std::string reset("\033[0m");

std::vector<int> getBitsOfUChar(unsigned char data)
{
	unsigned order = sizeof(unsigned char) * 8, mask = 1 << (order - 1);
	std::vector <int> binaryUnsignedChar;
	for (int i = order; i > 0; i--)
	{
		binaryUnsignedChar.push_back(mask & data ? 1 : 0);
		mask >>= 1;
	}
	return binaryUnsignedChar;
}

std::vector<int> getBitsOfDouble(double dataDouble)
{
	union {
		double data;
		int dataInt[2];
	};
	data = dataDouble;
	std::vector <int> binaryDouble;
	for (int j = 1; j >= 0; j--)
	{
		unsigned order = sizeof(int) * 8, mask = 1 << (order - 1);
		for (int i = order; i > 0; i--)
		{
			binaryDouble.push_back(dataInt[j] & mask ? 1 : 0);
			mask >>= 1;
		}
	}
	return binaryDouble;
}

void fromBinaryToDouble(std::vector <int> binaryDouble)
{
	union {
		double newValue;
		int newValueInt[2] = {0, 0};
	};
	for (int j = 1, count = 0; j >= 0; j--)
	{
		unsigned order = sizeof(int) * 8, mask;
		for (int i = 0; i < order; i++)
		{
			binaryDouble[count] ? mask = 1 << order - 1 - i : mask = 0 << order - 1 - i;
			newValueInt[j] |= mask;
			count++;
			//std::vector <int> binaryDouble = getBitsOfDouble(newValue);						//пошаговая визуализация процесса
			//std::cout << "binary representation: ";
			//for (int i = 0; i < sizeof(double) * 8; i++)
			//{
			//	if (i == 0) std::cout << blue << binaryDouble[i];
			//	else if (i > 0 && i < 12) std::cout << green << binaryDouble[i];
			//	else std::cout << red << binaryDouble[i];
			//}
			//std::cout << reset << '\n';
		}
	}
	std::cout << "value: " << newValue << '\n';
}

void fromBinaryToChar(std::vector<int> binaryUChar)
{
	char newChar = 0;
	unsigned order = sizeof(unsigned char) * 8, mask;
	for (int i = 0; i < order; i++)
	{
		binaryUChar[i] ? mask = 1 << order - 1 - i : mask = 0 << order - 1 - i;
		newChar |= mask; 
		//std::vector <int> binaryUChar = getBitsOfUChar(newChar);							//пошаговая визуализация процесса
		//std::cout << "binary representation: ";
		//for (int i = 0; i < sizeof(unsigned char) * 8; i++)
		//{
		//	std::cout << binaryUChar[i];
		//}
		//std::cout << '\n';
	}
	std::cout << "value: " << newChar << '\n';
}

