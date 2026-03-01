#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void)
{
	int n, *vector = 0;
	printf("Numarul de elemente:");
	scanf("%d", &n);

	printf("Citirea vectorului:\n");
	vector = citire_vector(n);

	printf("Afisarea vectorului citit:\n");
	afisare_vector(vector,n);

	qsort(vector, n, sizeof(vector[0]), comparare);
	printf("Afisarea vectorului sortat:\n");
	afisare_vector(vector,n);

	return 0;
}
