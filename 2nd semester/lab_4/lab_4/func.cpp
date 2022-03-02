#include <iostream>
#include <chrono>
#include "func.hpp"

namespace func
{
	void ADD(T_List* head, int age)
	{
		T_List* p = new T_List;
		p->age = age;

		p->next = head->next;
		head->next = p;
	}
	void ADD_LAST(T_List* head, int age)
	{
		T_List* tmp = new T_List;
		tmp->age = age;
		while (head->next != nullptr)
		{
			head = head->next; // Пока не дошли до конца списка
		}
		head->next = tmp;
		tmp->next = nullptr;
	}
	void PRINT(T_List* head)
	{
		T_List* p = head->next;
		while (p != nullptr)
		{
			std::cout << p->age << std::endl;
			p = p->next;
		}
	}
	void DELETE(T_List* head)
	{
		T_List* tmp;
		T_List* p = head;
		while (p->next != nullptr)
		{
			if (p->next->age % 2 == 0)
			{
				tmp = p->next;
				p->next = p->next->next;
				delete tmp;
			}
			else
				p = p->next;
		}
	}
	void CLEAR(T_List* head)
	{
		T_List* tmp;
		T_List* p = head->next;
		while (p != nullptr)
		{
			tmp = p;
			p = p->next;
			delete tmp;
		}
	}
	void DUPLICATE(T_List* head)
	{
		T_List* p = head->next;
		while (p != nullptr)
		{
			if (p->age % 2 == 1)
			{
				T_List* q = new T_List;
				q->next = p->next;
				p->next = q;
				q->age = p->age;
				p = p->next;
			}
			p = p->next;
		}
	}
	void SWAPSORT(T_List* head)
	{
		T_List* p = head->next;
		while (p->next->next != nullptr)
		{
			T_List* q = p->next;
			while (q->next != nullptr)
			{
				if (p->age > q->age)
					std::swap(p->age, q->age);
				q = q->next;
			}
			p = p->next;
		}
	}

}