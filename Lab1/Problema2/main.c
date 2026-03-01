#include <stdio.h>
#include "header.h"

int main(void)
{
	int n;
	double A;
	printf("Numarul de subdiviziuni:");
	scanf("%d", &n);

	A = aria(2, 3, n, &functie_calcul);
	printf("Aria calculata:%.4lf\n", A);
	
	return 0;
}
