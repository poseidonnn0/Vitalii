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

	Foo(const Foo& A) : i(A.i)
	{
		std::cout << "Copy Bar\n";
	}

	Foo& operator=(const Foo& A) 
	{
		std::cout << "\nOperator = \n";
	

		return *this;
	}


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
private:
	Bar(const Bar& B) = delete;
};

int main()
{
	std::unique_ptr<Foo> f(new Foo(100));
	std::unique_ptr<Foo> b(new Bar(200));

	*f = *b; 

	return 0;
}


