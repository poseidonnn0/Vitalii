#include "Matrix.hpp"
namespace math
{
Matrix::Matrix(int n, int m)
{
	std::cout << "Constructor" << std::endl;
	m_n = n;
	m_m = m;
	m_mat = new int* [m_n];
	for (int i = 0; i < m_n; i++)
		m_mat[i] = new int[m_m];
}

// Конструктор копирования
Matrix::Matrix(const Matrix& mat)
{
	std::cout << "Copy constructor" << std::endl;

	m_n = mat.m_n;
	m_m = mat.m_m;

	m_mat = new int* [m_n];
	for (int i = 0; i < m_n; i++)
		m_mat[i] = new int[m_m];

	for (int i = 0; i < m_n; i++)
		for (int j = 0; j < m_m; j++)
			m_mat[i][j] = mat.m_mat[i][j];
}

// Присваивание
Matrix& Matrix::operator=(const Matrix& mat)
{
	std::cout << "Operator =" << std::endl;

	m_n = mat.m_n;
	m_m = mat.m_m;

	for (int i = 0; i < m_n; i++)
		for (int j = 0; j < m_m; j++)
			m_mat[i][j] = mat.m_mat[i][j];

	return *this;
}

// Оператор сложения
Matrix Matrix::operator+(const Matrix& mat) {
	std::cout << "operator+" << std::endl;
	Matrix tmp(2, 3);
	for (int i = 0; i < m_n; i++)
		for (int j = 0; j < m_m; j++)
			tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
	return tmp;
}

// Оператор сложения  C += A <=> C = C + A
Matrix Matrix::operator+=(const Matrix& mat) {
	std::cout << "operator+=" << std::endl;
	Matrix tmp(2, 3);
	for (int i = 0; i < m_n; i++)
		for (int j = 0; j < m_m; j++)
			tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
	return tmp;
}

// Оператор умножения
Matrix Matrix::operator*(const Matrix& mat) {
	std::cout << "operator*" << std::endl;
	Matrix tmp(m_n, mat.m_m);
	for (int i = 0; i < m_n; i++)
	{
		for (int j = 0; j < m_m; j++)
		{
			tmp.m_mat[i][j] = 0;
			for (int k = 0; k < m_m; k++)
			{
				tmp.m_mat[i][j] += m_mat[i][k] * mat.m_mat[k][j];
			}
		}
	}

	return tmp;
}
// Деструктор
Matrix::~Matrix()
{
	std::cout << "Destructor" << std::endl;
	for (int i = 0; i < m_n; i++)
		delete[] m_mat[i];
	delete m_mat;
}

// Перегрузка оператора ввода
// 
std::istream& operator>>(std::istream& in, Matrix& mat)
{
	for (int i = 0; i < mat.m_n; i++)
		for (int j = 0; j < mat.m_m; j++)
			in >> mat.m_mat[i][j];
	return in;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& out, const Matrix& mat)
{
	out << "Matrix " << mat.m_n << "x" << mat.m_m << std::endl;
	for (int i = 0; i < mat.m_n; i++) {
		for (int j = 0; j < mat.m_m; j++)
			out << mat.m_mat[i][j] << " ";
		out << std::endl;
	}
	return out;
}

// Определитель матрицы
int Matrix::Det()
{
	if ((m_n == 2) && (m_m == 2))
	{
		return (m_mat[0][0] * m_mat[1][1] - m_mat[1][0] * m_mat[0][1]);
	}
	else if ((m_n == 3) && (m_m == 3))
	{
		return (m_mat[0][0] * (m_mat[1][1] * m_mat[2][2] - m_mat[2][1] * m_mat[1][2]) - (m_mat[0][1] * (m_mat[1][0] * m_mat[2][2] - m_mat[2][0] * m_mat[1][2])) + (m_mat[0][2] * (m_mat[1][0] * m_mat[2][1] - m_mat[1][1] * m_mat[2][0])));
	}
	else
	{
		std::cout << "\nOperation not work\n";
	}
}

//Транспонирование матрицы
Matrix Matrix::transposition()
{
	Matrix tmp(m_n, m_m);
	for (int i = 0; i < m_n; i++)
	{
		for (int j = 0; j < m_m; j++)
		{
			tmp.m_mat[i][j] = m_mat[j][i];
		}
	}
	return tmp;
}
//Обратная матрица
Matrix Matrix::inv()
{
	Matrix tmp(m_n, m_m);
	for (int i = 0; i < m_n; i++)
	{
		for (int j = 0; j < m_m; j++)
		{
			tmp.m_mat[i][j] = 0;
		}
	}
	if ((m_n == 2 && m_m == 2) || (m_n == 3 && m_m == 3)) 
	{
		int det = Det();
		if (det == 0) {
			std::cout << "Обратной матрицы не существует, Det = 0, (определитель равен 0)" << std::endl;
			return tmp;
		}
		if (m_n == 2) {
			tmp.m_mat[0][0] = m_mat[1][1] / det;
			tmp.m_mat[0][1] = -m_mat[0][1] / det;
			tmp.m_mat[1][0] = -m_mat[1][0] / det;
			tmp.m_mat[1][1] = m_mat[0][0] / det;
			return tmp;
		}
		if (m_n == 3) {
			tmp.m_mat[0][0] = (m_mat[1][1] * m_mat[2][2] - m_mat[2][1] * m_mat[1][2]) / det;
			tmp.m_mat[0][1] = -(m_mat[0][1] * m_mat[2][2] - m_mat[2][1] * m_mat[0][2]) / det;
			tmp.m_mat[0][2] = (m_mat[0][1] * m_mat[1][2] - m_mat[1][1] * m_mat[0][2]) / det;
			tmp.m_mat[1][0] = -(m_mat[1][0] * m_mat[2][2] - m_mat[2][0] * m_mat[1][2]) / det;
			tmp.m_mat[1][1] = (m_mat[0][0] * m_mat[2][2] - m_mat[2][0] * m_mat[0][2]) / det;
			tmp.m_mat[1][2] = -(m_mat[0][0] * m_mat[1][2] - m_mat[1][0] * m_mat[0][2]) / det;
			tmp.m_mat[2][0] = (m_mat[1][0] * m_mat[2][1] - m_mat[2][0] * m_mat[1][1]) / det;
			tmp.m_mat[2][1] = -(m_mat[0][0] * m_mat[2][1] - m_mat[2][0] * m_mat[0][1]) / det;
			tmp.m_mat[2][2] = (m_mat[0][0] * m_mat[1][1] - m_mat[1][0] * m_mat[0][1]) / det;
			return tmp;
		}
	}
	else
	{
		std::cout << "\nOperation not work\n";
	}
}
}