#pragma once
#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
	struct Node
	{
		T data;
		Node* next;

		Node(const T& data, Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};

	Node* top;
	int count;

public:
	Stack();
	Stack(const Stack<T>& other);
	~Stack();

	Stack<T>& operator=(const Stack<T>& other);

	void Push(const T& value);
	T Pop();
	T Top() const;

	bool IsEmpty() const;
	int GetCount() const;
	void Clear();
	void Print() const;
};

template <class T>
Stack<T>::Stack()
{
	this->top = nullptr;
	this->count = 0;
}

template <class T>
Stack<T>::Stack(const Stack<T>& other)
{
	this->top = nullptr;
	this->count = 0;

	if (other.top == nullptr)
	{
		return;
	}

	Node* current = other.top;
	Node* newTop = nullptr;
	Node* last = nullptr;

	while (current != nullptr)
	{
		Node* newNode = new Node(current->data);
		if (newTop == nullptr)
		{
			newTop = newNode;
			last = newNode;
		}
		else
		{
			last->next = newNode;
			last = newNode;
		}
		current = current->next;
	}

	this->top = newTop;
	this->count = other.count;
}

template <class T>
Stack<T>::~Stack()
{
	this->Clear();
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this == &other)
	{
		return *this;
	}

	this->Clear();

	if (other.top == nullptr)
	{
		return *this;
	}

	Node* current = other.top;
	Node* newTop = nullptr;
	Node* last = nullptr;

	while (current != nullptr)
	{
		Node* newNode = new Node(current->data);
		if (newTop == nullptr)
		{
			newTop = newNode;
			last = newNode;
		}
		else
		{
			last->next = newNode;
			last = newNode;
		}
		current = current->next;
	}

	this->top = newTop;
	this->count = other.count;
	return *this;
}

template <class T>
void Stack<T>::Push(const T& value)
{
	Node* newNode = new Node(value, this->top);
	this->top = newNode;
	this->count++;
}

template <class T>
T Stack<T>::Pop()
{
	if (this->IsEmpty())
	{
		cout << "Стек порожній!" << endl;
		return T();
	}

	Node* temp = this->top;
	T value = temp->data;
	this->top = this->top->next;
	delete temp;
	this->count--;
	return value;
}

template <class T>
T Stack<T>::Top() const
{
	if (this->IsEmpty())
	{
		cout << "Стек порожній!" << endl;
		return T();
	}

	return this->top->data;
}

template <class T>
bool Stack<T>::IsEmpty() const
{
	return this->top == nullptr;
}

template <class T>
int Stack<T>::GetCount() const
{
	return this->count;
}

template <class T>
void Stack<T>::Clear()
{
	while (!this->IsEmpty())
	{
		this->Pop();
	}
}

template <class T>
void Stack<T>::Print() const
{
	if (this->IsEmpty())
	{
		cout << "Стек порожній" << endl;
		return;
	}

	Node* current = this->top;
	cout << "Вершина -> ";
	while (current != nullptr)
	{
		cout << current->data;
		if (current->next != nullptr)
		{
			cout << " -> ";
		}
		current = current->next;
	}
	cout << endl;
}
