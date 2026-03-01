#include <math.h>
#include "header.h"

double I1(double x)
{
	return exp(-pow(x,2));
}

double I2(double x)
{
	return x;	
}

double I3(double x)
{
	return pow(x,2);
}

double I4(double x)
{
	return sqrt(1.0 + (1.0 / x));
}

double I5(double x)
{
	return x / (1.0 + x);
}

double Trapez(double l, double r, int n, double (*fun)(double))
{
	double ans, x;
	double dx = (r - l) / n;
	double eps = 1e-4;

	ans = ((*fun)(l) + (*fun)(r)) / 2;
	for(x = l + dx; r - x > eps;x += dx)
	{
		ans += (*fun)(x);
	}

	return ans * dx;
}

double Dreptunghi(double l, double r, int n, double (*fun)(double))
{
	double ans = 0, x;
	double dx = (r - l) / n;
	double eps = 1e-4;

	for(x = l + dx / 2.0; r - x > eps;x += dx)
	{
		ans += (*fun)(x);
	}

	return ans * dx;
}

double Simpson(double l, double r, int n, double (*fun)(double))
{
	n -= n % 2; // sa fie par, asa e conditia la aceasta metoda
	double ans = 0, x;
	double dx = (r - l) / n;
	int i;

	ans = (*fun)(l) + (*fun)(r);
	for(i = 1;i < n;++i)
	{
		x = l + i * dx;
		if(i % 2 == 0)
		{
			ans += 2 * (*fun)(x);
		}
		else
		{
			ans += 4 * (*fun)(x);
		}
	}	

	return (dx * ans) / 3.0;
}
