#include <iostream> 

class Foo
{
public:
	Foo(int j)
	{
		std::cout << "\nFoo const\n";
		/*this->*/i = new int[j];
	}
	virtual ~Foo() // + virtual 
	{
		std::cout << "\nFoo destr\n";
		delete[] i; // delete[] - удаляем массив, а не элемент 
	}

	//Foo* p; Нет деструктора 

protected: // protected 
	int* i;

};

class Bar : public Foo
{
public:
	Bar(int j/*,int k*/) : Foo(j) // Добавлена перегрузка (конструктор по умолчанию для потомка) 
	{
		std::cout << "\nBar const\n";
		i = new char[j];
	}
	virtual ~Bar() // + virtual 
	{
		std::cout << "\nBar destr\n";
		delete[] i; // delete[] - удаляем массив, а не элемент 
	}
protected: // protected 
	char* i;
};

int main()
{
	Foo* f = new Foo(100);
	Foo* b = new Bar(200);

	//(static_cast<Bar*>(f))->b; 

	//*f = *b; --> ДОДЕЛАТЬ 

	//f->p = new Bar(200); 

	delete f;
	delete b;

	return 0;
}


