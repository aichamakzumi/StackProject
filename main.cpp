#include <iostream>
#include <string>
#include <cstdlib>
#include "Stack.h"

using namespace std;

int main()
{
	system("chcp 65001 > nul");

	cout << "=== Тестування Stack<int> ===" << endl;
	Stack<int> intStack;

	cout << "Чи порожній стек? " << (intStack.IsEmpty() ? "Так" : "Ні") << endl;

	intStack.Push(10);
	intStack.Push(20);
	intStack.Push(30);
	intStack.Push(40);

	cout << "Кількість елементів: " << intStack.GetCount() << endl;
	cout << "Вміст стеку: ";
	intStack.Print();

	cout << "Елемент на вершині (Top): " << intStack.Top() << endl;

	cout << "Вилучено (Pop): " << intStack.Pop() << endl;
	cout << "Вилучено (Pop): " << intStack.Pop() << endl;

	cout << "Вміст після двох Pop: ";
	intStack.Print();
	cout << "Поточна кількість: " << intStack.GetCount() << endl;

	cout << "\n=== Тестування копіювання ===" << endl;
	Stack<int> copiedStack = intStack;
	cout << "Скопійований стек: ";
	copiedStack.Print();

	copiedStack.Push(999);
	cout << "Скопійований стек після Push(999): ";
	copiedStack.Print();
	cout << "Оригінальний стек не змінився: ";
	intStack.Print();

	cout << "\n=== Тестування Stack<string> ===" << endl;
	Stack<string> strStack;

	strStack.Push("Перший");
	strStack.Push("Другий");
	strStack.Push("Третій");

	cout << "Вміст рядкового стеку: ";
	strStack.Print();
	cout << "Вершина: " << strStack.Top() << endl;

	while (!strStack.IsEmpty())
	{
		cout << "Вилучено: " << strStack.Pop() << endl;
	}

	cout << "Після повного очищення: ";
	strStack.Print();
	cout << "Спроба вилучити з порожнього: ";
	strStack.Pop();

	cout << endl;
	system("pause");
	return 0;
}
