#include <iostream>
#include "include/render/object/Vector.h"
#include "include/utils/Defines.h"
int main()
{
	//int* a = new int[3];
	//*a = 1;
	//SafeDeleteArray(a);
	//if (a == nullptr)
	//{
	//	std::cout << "SV";
	//}

	rendering::Vector4f pos{ 1, 1, 1, 1 };
	pos.Normalized();
	auto norPos = pos;
	std::cout << norPos[0];
	std::cout << norPos[1];
	std::cout << norPos[2];
	std::cout << norPos[3];
}