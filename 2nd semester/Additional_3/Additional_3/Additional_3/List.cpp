#include <iostream>
#include "List.hpp"

void List::AddFirst(int age)
{
	Elem* temp = new Elem;
	temp->next = nullptr;                   // Указываем, что изначально по следующему адресу пусто
	temp->prev = nullptr;
	temp->age = age;
	if (head != nullptr)
	{   //Если список не пустой
		temp->next = head;               // Указываем на предыдущий первый элемент
		head->prev = temp;               // Предыдущий перый элемент теперь указывает на новый первый элемент
		head = temp;                     // Переназначаем первый элемент
	}
	else
	{                          // Если список пустой
		head = tail = temp;
	}
	Count++;
}

void List::AddEnd(int age)
{
	Elem* temp = new Elem;
	temp->next = nullptr;                   //Указываем, что изначально по следующему адресу пусто
	temp->prev = nullptr;
	temp->age = age;
	if (head != nullptr)
	{   //Если список не пустой
		temp->prev = tail;               //Указываем на предыдущий первый элемент
		tail->next = temp;               //Предыдущий перый элемент теперь указывает на новый первый элемент
		tail = temp;                     //Переназначаем первый элемент
	}
	else
	{                          //Если список пустой
		head = tail = temp;
	}
	Count++;
}

List::~List()                           //Деструктор
{
	while (head)                       //Пока по адресу на начало списка что-то есть
	{
		tail = head->next;             //Резервная копия адреса следующего звена списка
		delete head;                   //Очистка памяти от первого звена
		head = tail;                   //Смена адреса начала на адрес следующего элемента
	}
}

void List::Insert(int position)
{
	//if (position == 0)
	//{
	//	std::cout << "Input position: ";
	//	std::cin >> position;
	//}

	if (position == 0)
	{
		std::cout << "Incorrect position !!!\nВведите позицию начиная отсчёт не с 0, а с 1\nPosition: ";
		std::cin >> position;
	}

	if (((position > 1) && (position > Count + 1)) || (position < 1))// Позиция от 1 до Count?
	{
		// Неверная позиция
		std::cout << "Incorrect position !!!\n";
		return;
	}
	// Если вставка в конец списка
	if (position == Count + 1)
	{
		// Вставляемые данные
		int data;
		std::cout << "Input new number: ";
		std::cin >> data;
		// Добавление в конец списка
		AddEnd(data);
		return;
	}
	else if (position == 1)
	{
		// Вставляемые данные
		int data;
		std::cout << "Input new number: ";
		std::cin >> data;
		// Добавление в начало списка
		AddFirst(data);
		return;
	}

	// Счетчик
	int i = 1;

	// Отсчитываем от головы n - 1 элементов
	Elem* Ins = head;

	while (i < position)
	{
		// Доходим до элемента, 
		// перед которым вставляемся
		Ins = Ins->next;
		i++;
	}

	// Доходим до элемента, 
	// который предшествует
	Elem* PrevIns = Ins->prev;

	// Создаем новый элемент
	Elem* tmp = new Elem;

	// Вводим данные
	std::cout << "Input new number: ";
	std::cin >> tmp->age;

	// настройка связей
	if (PrevIns != 0 && Count != 1)
		PrevIns->next = tmp;

	tmp->next = Ins;
	tmp->prev = PrevIns;
	Ins->prev = tmp;

	Count++;
}

void List::ShowList() // Вывод списка в обоих направлениях
{
	Elem* temp = new Elem;
	//ВЫВОДИМ СПИСОК С НАЧАЛА
	temp = head;                       //Временно указываем на адрес первого элемента
	while (temp != nullptr)              //Пока не встретим пустое значение
	{
		std::cout << temp->age << " ";        //Выводим каждое считанное значение на экран
		temp = temp->next;             //Смена адреса на адрес следующего элемента
	}
	std::cout << "\n";

	//ВЫВОДИМ СПИСОК С КОНЦА
	temp = tail;                   //Временный указатель на адрес последнего элемента

	while (temp != nullptr)               //Пока не встретится пустое значение
	{
		std::cout << temp->age << " ";        //Выводить значение на экран
		temp = temp->prev;             //Указываем, что нужен адрес предыдущего элемента
	}
	std::cout << "\n";
}


void List::COUNT()
{
	std::cout << "Count = " << Count;
}

void List::Del(int position)
{
	if (position == 0)
	{
		std::cout << "Incorrect position !!!\nВведите позицию начиная отсчёт не с 0, а с 1\nPosition: ";
		std::cin >> position;
	}
	if ((position < 1) || (position > Count)) // Позиция от 1 до Count?
	{
		// Неверная позиция
		std::cout << "Incorrect position !!!\n";
		return;
	}
	// Счетчик
	int i = 1;

	// Отсчитываем от головы n - 1 элементов
	Elem* Del = head;

	while (i < position)
	{
		// Доходим до элемента, 
		// перед которым вставляемся
		Del = Del->next;
		i++;
	}
	// Доходим до элемента, 
	// который предшествует
	Elem* PrevDel = Del->prev;
	Elem* AfterDel = Del->next; 	// Доходим до элемента, который следует за удаляемым
	// Если удаляем не голову
	if (PrevDel != 0 && Count != 1)
	{
		PrevDel->next = AfterDel;
	}
	// Если удаляем не хвост
	if (AfterDel != 0 && Count != 1)
	{
		AfterDel->prev = PrevDel;
	}
	// Удаляются крайние?
	if (position == 1)
	{
		head = AfterDel;
	}
	if (position == Count)
	{
		tail = PrevDel;
	}
	// Удаление элемента
	delete Del;
	Count--;
}

void List::CLEAR()
{
	while (Count != 0)
	{
		List::Del(1);
	}
}