#include <math.h>
#include "header.h"

double functie_calcul(double x)
{
	return sin(exp(2 * x) + 3.0);
}

double aria(double l, double r, int n, double (*f)(double))
{
	double ans = 0, dx = (r - l) / n;
	double eps = 1e-4, x;
	
	ans += ((*f)(l) + (*f)(r)) / 2;
	for(x = l + dx; r - x > eps; x += dx)
	{
		ans += (*f)(x);
	}

	return ans * dx;
}
