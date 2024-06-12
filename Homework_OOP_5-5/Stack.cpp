#include "stack.h"
#include "list.h"
#include "list.cpp"

template <class valtype>
Stack<valtype>::Stack()
{
	list = new List<valtype>();
}

template <class valtype>
Stack<valtype>::Stack(const Stack<valtype>& s)
{
	this->list = new List<valtype>(*(s.list));
}

template <class valtype>
Stack<valtype>::~Stack()
{
	delete this->list;
}

template <class valtype>
int Stack<valtype>::isEmpty() const
{
	return list->getFirst() == 0;
}

template <class valtype>
int Stack<valtype>::isFull() const
{
	NODE<valtype>* tmp;
	try {
		tmp = new NODE<valtype>;
	}
	catch (...) {
		return 1;
	}
	delete tmp;
	return 0;
}

template <class valtype>
void Stack<valtype>::push(valtype key)
{
	if (isFull()) throw "Stack is full";
	list->insertFirst(key);
}

template <class valtype>
valtype Stack<valtype>::pop()
{
	if (isEmpty()) throw "Stack is empty";
	valtype result = list->getFirst()->key;
	list->erase(result);
	return result;
}

template <class valtype>
valtype Stack<valtype>::look()
{
	if (isEmpty()) throw "Stack is empty";
	return list->getFirst()->key;
}


template <class valtype>
Stack<valtype>& Stack<valtype>::operator =(const Stack<valtype>& s) {
	if (this == &s)
		return *this;

	this->Size = s.Size;

	// Очистка текущего списка
	while (!isEmpty())
	{
		pop();
	}

	// Копирование элементов из s в текущий стек
	Node<valtype>* temp = s.head;
	while (temp)
	{
		push(temp->data);
		temp = temp->pNext;
	}

	return *this;
}



template <class valtype>
NODE<valtype>* Stack<valtype>::operator+(const Stack<valtype>& s) {
	Stack<valtype> result(*this);  // Копируем текущий стек

	NODE<valtype>* temp = s.head;
	while (temp) {
		result.push(temp->data);
		temp = temp->pNext;
	}

	return result.head;
}

template <class valtype>
NODE<valtype>* Stack<valtype>::operator*(const Stack<valtype>& s) {
	Stack<valtype> result;  // Создаем новый стек для результата

	NODE<valtype>* temp1 = this->head;
	NODE<valtype>* temp2 = s.head;

	while (temp1 && temp2) {
		if (temp1->data == temp2->data) {
			result.push(temp1->data);
		}
		temp1 = temp1->pNext;
		temp2 = temp2->pNext;
	}

	return result.head;
}