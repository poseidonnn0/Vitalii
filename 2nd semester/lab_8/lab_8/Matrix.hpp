#ifndef __MATRIX_H__
#define __MATRIX_H__
#include <iostream>
namespace math
{

// MY_DEBUG
//#define MY_DEBUG 

template<typename T, int N, int M>
struct MasWrapper
{
	T mas[N][M];
};

template<typename T, int N, int M>
class Matrix
{
public:
	Matrix()
	{
#ifdef MY_DEBUG
		std::cout << "Constructor" << std::endl;
#endif
		m_n = N;
		m_m = M;
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = 0;
	}
	//
	~Matrix()
	{
#ifdef MY_DEBUG
		std::cout << "Destructor" << std::endl;
#endif
	}
	//

	Matrix(const T mas[N][M])
	{
#ifdef MY_DEBUG
		std::cout << "Constructor" << std::endl;
#endif
		m_n = N;
		m_m = M;
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = mas[i][j];
	}

	Matrix(const MasWrapper<T, N, M>& mas)
	{
#ifdef MY_DEBUG
		std::cout << "Constructor" << std::endl;
#endif
		m_n = N;
		m_m = M;
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = mas.mas[i][j];
	}

	Matrix(const Matrix<T, N, M>& mat)
	{
#ifdef MY_DEBUG
		std::cout << "Copy constructor" << std::endl;
#endif

		m_n = mat.m_n;
		m_m = mat.m_m;

		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = mat.m_mat[i][j];
	}

	int getN() const { return m_n; }
	int getM() const { return m_m; }
	int get(int i, int j) const { return m_mat[i][j]; }
	void set(int i, int j, T data) { m_mat[i][j] = data; }

	template<typename T, int N, int M>
	Matrix<T, N, M>& operator=(const Matrix<T, N, M>& mat)
	{
#ifdef MY_DEBUG
		std::cout << "Operator =" << std::endl;
#endif

		m_n = mat.getN();
		m_m = mat.getM();

		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_mat[i][j] = mat.get(i, j);

		return *this;
	}

	template<typename T, int N, int M>
	Matrix<T, N, M> operator+(const Matrix<T, N, M>& mat)
	{
#ifdef MY_DEBUG
		std::cout << "operator+" << std::endl;
#endif
		Matrix<T, N, M> tmp;
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
		return tmp;
	}

	template<typename T, int N, int M>
	Matrix<T, N, M> operator*(const Matrix<T, N, M>& mat)
	{
#ifdef MY_DEBUG
		std::cout << "operator*" << std::endl;
#endif
		Matrix<T, N, M> tmp;

		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < mat.getM(); j++)
			{
				int sum = 0;
				for (int k = 0; k < m_m; k++)
					sum += m_mat[i][k] * mat.get(i, j);
				tmp.set(i, j, sum);
			}

		return tmp;
	}
	
	T Det() 
	{
		if constexpr ((N == 2) && (M == 2))
		{
			return (m_mat[0][0] * m_mat[1][1] - m_mat[1][0] * m_mat[0][1]);
		}
		if constexpr ((N == 3) && (M == 3))
		{
			return (m_mat[0][0] * (m_mat[1][1] * m_mat[2][2] - m_mat[2][1] * m_mat[1][2]) - (m_mat[0][1] * (m_mat[1][0] * m_mat[2][2] - m_mat[2][0] * m_mat[1][2])) + (m_mat[0][2] * (m_mat[1][0] * m_mat[2][1] - m_mat[1][1] * m_mat[2][0])));
		}
		else
		{
			std::cout << "\nOperation not work\n";
		}
	}

	Matrix transposition()
	{
		Matrix<T, N, M> tmp;
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
			{
				tmp.m_mat[i][j] = m_mat[j][i];
			}
		}
		return tmp;
	}


	Matrix inv()
	{
		Matrix<T, N, M> tmp;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				tmp.m_mat[i][j] = 0;
			}
		}
		if ((N == 2 && M == 2) || (N == 3 && M == 3))
		{
			int det = Det();
			if (det == 0) {
				std::cout << "Обратной матрицы не существует, Det = 0, (определитель равен 0)" << std::endl;
				return tmp;
			}
			if (N == 2) {
				tmp.m_mat[0][0] = m_mat[1][1] / det;
				tmp.m_mat[0][1] = -m_mat[0][1] / det;
				tmp.m_mat[1][0] = -m_mat[1][0] / det;
				tmp.m_mat[1][1] = m_mat[0][0] / det;
				return tmp;
			}
			if (N == 3) {
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

	template<typename T, int N, int M>
	friend std::istream& operator>>(std::istream& os, Matrix<T, N, M>& mat);

	template<typename T, int N, int M>
	friend std::ostream& operator<<(std::ostream& os, const Matrix<T, N, M>& mat);

private:
	int m_n, m_m;
	T m_mat[N][M];
};

template<typename T, int N, int M>
std::istream& operator>>(std::istream& in, Matrix<T, N, M>& mat)
{
	for (int i = 0; i < mat.m_n; i++)
		for (int j = 0; j < mat.m_m; j++)
			in >> mat.m_mat[i][j];
	return in;
}

template<typename T, int N, int M>
std::ostream& operator<<(std::ostream& out, const Matrix<T, N, M>& mat)
{
	out << "Matrix " << mat.m_n << "x" << mat.m_m << std::endl;
	for (int i = 0; i < mat.m_n; i++) {
		for (int j = 0; j < mat.m_m; j++)
			out << mat.m_mat[i][j] << " ";
		out << std::endl;
	}
	return out;
}

using Vec2i = Matrix<int, 2, 1>;
using Vec2d = Matrix<double, 2, 1>;
using Mat22i = Matrix<int, 2, 2>;
using Mat22d = Matrix<double, 2, 2>;
using Mat33i = Matrix<int, 3, 3>;
using Mat33d = Matrix<double, 3, 3>;

}
#endif
