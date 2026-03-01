#ifndef HEADER_H_
#define HEADER_H_

struct MENU_ITEM{
	char *nume;
	double (*f)(double, double , int, double(*)(double));
};

typedef struct MENU_ITEM MENU_ITEM;

MENU_ITEM meniu(void);
double functie_calc(double x);
double Trapez(double l, double r, int n, double (*fun)(double));
double Dreptunghi(double l, double r, int n, double (*fun)(double));
double Simpson(double l, double r, int n, double (*fun)(double));

#endif
