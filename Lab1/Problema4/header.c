#include <stdio.h>
#include <math.h>
#include "header.h"

MENU_ITEM meniu(void)
{
	MENU_ITEM m[3] = {{"Metoda Trapezului", Trapez},
					  {"Metoda Dreptunghiului", Dreptunghi},
					  {"Metoda Simpson", Simpson}};

	int choice;
	printf("-------------Meniu--------------\n");
	printf("1.Metoda Trapezlui\n");
	printf("2.Metoda Dreptunghilor\n");
	printf("3.Metoda Simpson\n");
	printf("Alegerea >> ");
	scanf("%d", &choice);

	return m[choice - 1];
}

double functie_calc(double x)
{
	return sin(exp(2 * x) + 3.0);
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
