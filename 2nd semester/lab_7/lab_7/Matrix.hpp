
#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <iostream>
namespace math
{
class Matrix
{
	// Абстракция
	// Инкапсуляция
	// Использование вне класса
public:
	// Конструктор
	Matrix(int n, int m);

	// Конструктор копирования
	Matrix(const Matrix& mat);
	// Присваивание
	Matrix& operator=(const Matrix& mat);
	// Оператор сложения
	Matrix operator+(const Matrix& mat);

	// Оператор сложения  C += A <=> C = C + A
	Matrix operator+=(const Matrix& mat);
	// Оператор умножения
	Matrix operator*(const Matrix& mat);

	// Деструктор
	~Matrix();
	// friend - позволяет функции иметь доступ к private полям/методам класса
	friend std::istream& operator>>(std::istream& os, Matrix& mat);
	friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);

	int Det();

	Matrix transposition();

	Matrix inv();

	// Использование внутри класса
private:
	int m_n, m_m;		// Поле
	int n;
	int** m_mat; // Matrix
};
}
#endif