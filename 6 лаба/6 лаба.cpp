#include "List.h"

void menu()
{
	std::cout << "1 - добавить элемент в конец первого списка.\n2 - добавить элемент в конец второго списка.\n"
		<< "3 - добавить элемент по итератору в указанное место первого списка.\n4 - удалить элемент по итератору в указанном месте первого списка.\n"
		<< "5 - объеденить два списка без сортировки.\n6 - объеденить два списка с сортировкой.\n0 - выход:\n";
}

int main()
{
	setlocale(LC_ALL, "rus");
	List<int> list;
	List<int> list2;
	
	menu();
	char work;
	std::cin >> work;
	while (work != '0')
	{
		switch (work) 
		{
		case '1':
		{
			int a;
			std::cout << "Введите число, которое хотите добавить в конец первого списка: ";
			std::cin >> a;
			list.append(a);
			list.show();
			break;
		}
		case '2':
		{
			int a;
			std::cout << "Введите число, которое хотите добавить в конец второго списка: ";
			std::cin >> a;
			list2.append(a);
			list2.show();
			break;
		}
		case '3':
		{
			int iter, number;
			std::cout << "Введите число, которое хотите добавить и номер элемента в списке, после которого хотите его добавить: ";
			std::cin >> number >> iter;
			//добавление элемента по итератору
			auto it = list.begin();
			int count = 0;
			while (count < iter - 1)
			{
				++it;
				count++;
			}
			list.addAfterNode(it.getNode(), number);
			list.show();
			//
			break;
		}
		case '4':
		{
			int iter;
			std::cout << "Введите номер элемента в списке, который хотите удалить: ";
			std::cin >> iter;
			//удаление элемента по итератору
			auto it = list.begin();
			int count = 0;
			while (count < iter - 1)
			{
				++it;
				count++;
			}
			list.deleteAfterNode(it.getNode());
			list.show();
			//
			break;
		}
		case '5':
		{
			//объединение списков
			List<int> newList;
			auto it = list.begin();
			while (it != list.end())
			{
				newList.append(*it);
				++it;
			}
			newList.append(*it);
			it = list2.begin();
			while (it != list2.end())
			{
				newList.append(*it);
				++it;
			}
			newList.append(*it);
			newList.show();
			//
			break;
		}
		case '6':
		{
			//объединение с сортировкой
			List<int> newList;
			auto it = list.begin();
			while (it != list.end())
			{
				newList.append(*it);
				++it;
			}
			newList.append(*it);
			it = list2.begin();
			while (it != list2.end())
			{
				newList.append(*it);
				++it;
			}
			newList.append(*it);
			newList.sort();
			newList.show();
			//
			break;
		}
		}
		menu();
		std::cin >> work;
	}
}