#ifndef HEADER_H_
#define HEADER_H_

struct Meniu_item{
	char *name;
	double (*fun)(double **, int , int);
};
typedef struct Meniu_item Meniu_item;

double **citire_matrice(int n, int m);
void afisare_matrice(double **mat, int n, int m);
Meniu_item meniu(void);
double Norma1(double **mat, int n, int m);
double Norma_infinit(double **mat, int n, int m);
double Norma_euclid(double **mat, int n, int m);

#endif
