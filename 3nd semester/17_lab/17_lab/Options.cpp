#include "Options.hpp"
namespace Functions
{
void Task5(char s, std::ifstream& in, Tree::Elem*& root)
{
	int d;
	if (s == '+')
	{
		in >> d;
		Tree::ADD(d, root);
	}
	if (s == '-')
	{
		in >> d;
		Tree::DELETE(d, root);
	}
	if (s == '?')
	{
		in >> d;
		Tree::SearchCount(d, root, 1); // начало подсчёта  глубины с 1
	}
	if (s == 'E')
	{
		return;
	}
}
}
