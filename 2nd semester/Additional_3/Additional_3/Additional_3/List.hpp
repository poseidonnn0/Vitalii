#pragma once

struct Elem
{
	int age;
	Elem* next, * prev;                 // Указатели на адреса следующего и предыдущего элементов списка
};

class List
{
	Elem* head, * tail;                 // Указатели на адреса начала списка и его конца
	int Count;
public:
	List() :head(nullptr), tail(nullptr), Count(0) {};
	~List();
	void ShowList();
	void AddFirst(int age);              // Добавление элемента в начало списка
	void Insert(int position); // Добавления элемента по его заданной позиции
	void AddEnd(int age); // Добавление элемента в конец списка
	void COUNT();
	void CLEAR();
	void Del(int position);
};