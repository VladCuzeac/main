#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int *citire_vector(int n)
{
	int i;
	int *v = (int*) malloc(n * sizeof(int));
	if(v == 0)
	{
		fprintf(stderr,"Alocare esuata\n");
		exit(EXIT_FAILURE);
	}
	
	for(i = 0;i < n;++i)
	{
		scanf("%d", v + i);
	}
	return v;
}

void afisare_vector(int *a, int n)
{
	int i;
	for(i = 0;i < n;++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int comparare(const void *a, const void *b)
{
	return *((int*) a) - *((int*) b);
}
