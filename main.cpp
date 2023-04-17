#include "Graph.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "");
	Graph scg;

	scg.addPerson("Олег"); 
	scg.addPerson("Никита");
	scg.addPerson("Настя");
	scg.addPerson("Ваня");
	scg.addPerson("Женя");
	scg.addPerson("Света");
	scg.addPerson("Дима");
	scg.addPerson("Рита");
	scg.addPerson("Роман");
	scg.addPerson("Анна");

	scg.addFriend(1, 2);
	scg.addFriend(2, 3);
	scg.addFriend(3, 4);
	scg.addFriend(4, 5);
	scg.addFriend(5, 6);
	scg.addFriend(6, 7);
	scg.addFriend(7, 8);
	scg.addFriend(8, 9);
	scg.addFriend(9, 10);

	for (size_t i = 0; i < scg.getPersonsCount(); i++)
	{
		for (size_t j = i + 1; j < scg.getPersonsCount(); j++)
		{
			size_t distance = scg.findCouplesThroughThreeHandshakes(i, j);
			if (distance <= 3)
			std::cout << scg.findPersonByIndex(i) << " дружит с " << scg.findPersonByIndex(j) << std::endl;
		}
	}
	return 0;
}