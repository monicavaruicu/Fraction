#include <iostream>
#include "Fraction.h"

int main()
{

	int n;
	std::cout << "Degree of the polynomial: ";
	std:: cin >> n;

	Fraction** roots = new Fraction*[n];
	int itr = -1;
	int* v = new int[n + 1];

	std::cout << "Coefficients of the polynomial (x to x^n): ";

	for (int i = n; i >= 0; i--)
		std::cin >> v[i];

	for (int p = 1; p <= abs(v[0]); p++)
	{
		if (v[0] % p == 0)
		{
			for (int q = 1; q <= abs(v[n]); q++)
			{
				if (v[n] % q == 0)
				{
					{
						Fraction fr(p, q);
						if (fr.greatestCommonFactor() == 1 && fr.solveEcuation(fr, n, v))
						{
							roots[++itr] = new Fraction;
							*(*roots + itr) = fr;
						}
					}

					{
						Fraction fr(-p, q);
						if (fr.greatestCommonFactor() == 1 && fr.solveEcuation(fr, n, v))
						{
							roots[++itr] = new Fraction;
							*(*roots + itr) = fr;

						}
					}
				}
			}
		}
	}

	std::cout << "Solution: ";
	for (int i = 0; i <= itr; i++)
		std::cout << *(*roots + i) << " ";

	return 0;
}
