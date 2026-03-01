#include <stdio.h>
#include "header.h"

int main(void)
{
	int n;
	long long val_fact;
	printf("Introduceti valoarea lui n:");
	scanf("%d", &n);

	val_fact = factorial(n);
	printf("n! = %lld\n", val_fact);

	return 0;
}
