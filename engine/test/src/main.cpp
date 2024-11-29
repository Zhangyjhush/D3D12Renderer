#include <iostream>
#include "include/render/object/Vector.h"
int main()
{
	rendering::Vector<float, 4> pos{ 1, 2, 3, 4 };
	pos[0] = 10;
	std::cout << pos[0];
}