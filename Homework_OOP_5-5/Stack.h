
#pragma once

#include "list.h"

template <class valtype>
class Stack {
private:
	List<valtype>* list;
public:
	Stack();
	Stack(const Stack<valtype>& s);
	// Конструктор копирования
	Stack(const Stack& copy) {
		if (!other.list) {
			list = nullptr;
			return;
		}

		node<valtype>* tail = nullptr;
		node<valtype>* phead = new node<valtype>(copy.list->getFirst()->data);
		tail = phead;

		this->size++;

		ffor(node<valtype>*p = copy.list->getFirst()->next; p; p = p->next)
		{
			tail = tail->pnext = new node<valtype>(p->data);
			this->size++;
		}
	}
	~Stack();
	int isEmpty() const;
	int isFull() const;
	void push(valtype key);
	valtype pop();
	valtype look();
	Stack<valtype>& operator =(const Stack<valtype>& s);
	NODE<valtype>* Stack<valtype>::operator+(const Stack<valtype>& s)
	NODE<valtype>* Stack<valtype>::operator*(const Stack<valtype>& s)

};

template <class valtype>
Stack<valtype>::Stack();

template <class valtype>
Stack<valtype>::Stack(const Stack<valtype>& s);

template <class valtype>
Stack<valtype>::~Stack();

template <class valtype>
int Stack<valtype>::isEmpty() const;

template <class valtype>
int Stack<valtype>::isFull() const;

template <class valtype>
void Stack<valtype>::push(valtype key);

template <class valtype>
valtype Stack<valtype>::pop();

template <class valtype>
valtype Stack<valtype>::look();

template <class valtype>
Stack<valtype>& Stack<valtype>::operator =(const Stack<valtype>& s);

template <class valtype>
NODE<valtype>* Stack<valtype>::operator+(const Stack<valtype>& s);

template <class valtype>
NODE<valtype>* Stack<valtype>::operator*(const Stack<valtype>& s)


