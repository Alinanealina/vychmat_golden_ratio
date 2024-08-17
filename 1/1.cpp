#include <iostream>
using namespace std;
double f(double x)
{
	return (x * x - 4 * x);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int i = 1;
	double a = 0, b = 6, a0 = a, b0 = b, h1, h2, eps = pow(10, -8), l1, l2, x;
	do
	{
		cout << " Шаг " << i << ": [" << a << "; " << b << "], l1 = ";
		if (i == 1)
		{
			l1 = a + 0.382 * (b - a);
			l2 = a + 0.618 * (b - a);
			h1 = f(l1);
			h2 = f(l2);
		}
		else
		{
			if (a0 != a)
			{
				l1 = l2;
				h1 = h2;
				l2 = a + 0.618 * (b - a);
				h2 = f(l2);
			}
			else if (b0 != b)
			{
				l2 = l1;
				h2 = h1;
				l1 = a + 0.382 * (b - a);
				h1 = f(l1);
			}
		}
		a0 = a;
		b0 = b;
		cout << l1 << ", l2 = " << l2 << ", f(l1) = " << h1 << ", f(l2) = " << h2;
		if (h1 > h2)
		{
			a = l1;
			cout << ", f(l1) > f(l2) -> a = " << l1 << endl;
		}
		else
		{
			b = l2;
			cout << ", f(l1) <= f(l2) -> b = " << l2 << endl;
		}
		x = (a + b) / 2;
		cout << " x = " << x << ", f(x) = " << f(x) << ", eps = " << (b - a) / 2 << endl << endl;
		i++;
	} while ((b - a) / 2 > eps);
	return 0;
}