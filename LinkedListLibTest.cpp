#include <iostream>
#include "LinkedList.hpp"

class Test : public LinkProperty<Test>
{
public:
	Test(int _Value) : Value(_Value), LinkProperty(this)
	{
		std::cout << "Test()" << std::endl;
	}

	bool operator== (const Test& Other) const
	{
		return Value == Other.Value;
	}

public:
	int Value;
};

int main()
{
	LinkedList<Test> List;

	Test* pInt1 = new Test(1);
	Test* pInt2 = new Test(2);
	Test* pInt3 = new Test(3);

	List.Link(pInt1);
	List.Link(pInt2);
	List.Link(pInt3);

	for (auto& ele : List)
	{
		std::cout << ele.Value << " ";
	}

	std::cout << std::endl;

	List.Unlink(pInt2);

	for (auto& ele : List)
	{
		std::cout << ele.Value << " ";
	}

	List.ClearLink();

	delete pInt1;
	delete pInt2;
	delete pInt3;

	return 0;
}