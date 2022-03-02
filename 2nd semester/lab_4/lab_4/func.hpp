#pragma once
#include <iostream>
#include <chrono>

namespace func
{
	class Timer
	{
	private:
		// Псевдонимы типов используются для удобного доступа к вложенным типам
		using clock_t = std::chrono::high_resolution_clock;
		using second_t = std::chrono::duration<double, std::ratio<1> >;
		std::chrono::time_point<clock_t> m_beg;
	public:
		Timer() : m_beg(clock_t::now())
		{
		}
		void reset()
		{
			m_beg = clock_t::now();
		}
		double elapsed() const
		{
			return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
		}
	};
	struct T_List
	{
		T_List* next;
		int age;
	};

	void ADD(T_List* head, int age);
	void ADD_LAST(T_List* head, int age);
	void PRINT(T_List* head);
	void DELETE(T_List* head);
	void CLEAR(T_List* head);
	void DUPLICATE(T_List* head);
	void SWAPSORT(T_List* head);
}