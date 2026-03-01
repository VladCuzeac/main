#include <stdio.h>
#include "header.h"

int main(void)
{
	int n, m;
	double **mat = 0, norma;
	Meniu_item alegere;

	printf("n = ");
	scanf("%d", &n);
	printf("m = ");
	scanf("%d", &m);

	printf("Citirea matricei:\n");
	mat = citire_matrice(n, m);

	printf("Afisare matrice:\n");
	afisare_matrice(mat, n, m);

	alegere = meniu();
	norma = alegere.fun(mat,n, m);
	printf("%s\n%.4lf\n", alegere.name, norma);

	return 0;
}
