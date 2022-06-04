#include <iostream> 
#include <memory>
class Foo
{

public:
	Foo(int j)
	{
		l = j;
		std::cout << "\nFoo const\n";
		i = new int[j];

		for (int z = 0; z < l; z++)
		{
			z[i] = z + 1;
		}

	}

	void Write()
	{
		for (int k = 0; k < l; k++)
		{
			std::cout << '\n' << i[k] << '\n';
		}
	}

	virtual ~Foo() // + virtual 
	{
		std::cout << "\nFoo destr\n";
		delete[] i; // delete[] - удаляем массив, а не элемент 
	}

	Foo& operator=(const Foo& A)
	{
		std::cout << "\nOperator = \n";
	
		return *this;
	}

	Foo(const Foo& A) :
		i(A.i)
	{
		std::cout << "Copy Bar\n";
	}


	friend std::ostream& operator<<(std::ostream& os, const int** i)
	{

	}
protected: // protected 
	int* i;
	int l;

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
	//Bar(const Bar& B) = delete;
};

int main()
{
	
	std::unique_ptr<Foo> f = std::make_unique<Foo>(2);
	std::unique_ptr<Foo> b = std::make_unique<Bar>(3);

	f->Write();
	std::cout << "==========\n==========";
	b->Write();

	*f = *b; 

	f->Write();
	std::cout << "==========\n==========";
	b->Write();


	Foo f1(1000);
	Foo* p = new Foo(0);
	*p = f1;
	//Foo f2(f1);

	return 0;
}


