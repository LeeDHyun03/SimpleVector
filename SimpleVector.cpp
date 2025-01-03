#include <iostream>
#include "SimpleVector.h"

int main()
{
	SimpleVector<int> vec(10);

	vec.Push_Back(3);
	vec.Push_Back(6);
	vec.Push_Back(5);
	vec.Push_Back(2);
	vec.Push_Back(1);
	vec.Push_Back(10);
	vec.Push_Back(14);
	vec.Push_Back(12);
	vec.Push_Back(11);
	vec.Push_Back(19);
	vec.Push_Back(21);
	vec.Push_Back(25);
	vec.Push_Back(16);
	vec.Push_Back(18);
	vec.sortData();
	for (int i = 0; i < vec.capacity(); i++) std::cout << vec.GetVectorIndex(i) << std::endl;
	for (int i = 1; i < 5; i++)
	{
		vec.Pop_Back();
	}
	std::cout << "----------------------------\n";
	for (int i = 0; i < vec.capacity(); i++) std::cout << vec.GetVectorIndex(i) << std::endl;
	vec.resize(20);
	std::cout << "----------------------------\n";
	for (int i = 0; i < vec.capacity(); i++) std::cout << vec.GetVectorIndex(i) << std::endl;
	return 0;
}
