#include <stdio.h>
#include "header.h"

int main(void)
{
	int n;
	double aria = 0;
	MENU_ITEM alegere;

	printf("Numarul de diviziuni:");
	scanf("%d", &n);
	
	alegere = meniu();
	aria = alegere.f(2,3,n, functie_calc);

	printf("Aria calculata prin %s este %.4lf", alegere.nume, aria);

	return 0;
}
