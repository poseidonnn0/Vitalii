#include <iostream>
#include <algorithm> 
int main()
{
	int Q1, P1, Q2, P2, A, mA, min1 = INT_MAX, SUM=0, G, D=0, count1 = 0, count2 = 0;
    std::cin >> Q1 >> P1 >> Q2 >> P2 >> A;
	if (Q2 > Q1) { std::swap(Q2, Q1); std::swap(P2, P1); }
	mA = A;
	while (mA > 0) { count1++; mA -= Q1; }
	G = count1;
	while (G != 0)
	{
		SUM = G * P1 + D * P2;
		min1 = std::min(SUM, min1);
		G--;
		while (G * Q1 + D * Q2 < A) { D++; }
	}
	while (count2 * Q2 < A) { count2++; }
	min1 = std::min(SUM, min1);
	std::cout << '\n' << min1;
}