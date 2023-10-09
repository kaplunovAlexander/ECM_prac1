#pragma once

#include <iostream>
#include <vector>

std::vector <int> getBitsOfUChar(unsigned char data);

std::vector <int> getBitsOfDouble(double data);

void fromBinaryToDouble(std::vector <int> binaryDouble);

void fromBinaryToChar(std::vector <int> binaryUChar);