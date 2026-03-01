#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "header.h"

double **citire_matrice(int n, int m)
{
	int i, j;
	double **mat = (double **) malloc(n * sizeof(double *));
	if(mat == 0)
	{
		fprintf(stderr,"Alocare esuata\n");
		exit(EXIT_FAILURE);
	}	

	for(i = 0;i < n;++i)
	{
		*(mat + i) = (double *) malloc(m * sizeof(double));
		if(*(mat + i) == 0)
		{
			fprintf(stderr,"Aloacare esuata\n");
			exit(EXIT_FAILURE);
		}
	}
	
	for(i = 0;i < n;++i)
	{
		for(j = 0;j < m;++j)
		{
			scanf("%lf", (*(mat + i) + j));
		}
	}
	return mat;
}

void afisare_matrice(double **mat, int n, int m)
{
	int i, j;
	for(i = 0;i < n;++i)
	{
		for(j = 0;j < m;++j)
		{
			printf("%.2lf ", mat[i][j]);
		}
		printf("\n");
	}
}

Meniu_item meniu(void)
{
	Meniu_item m[3] = {{"Calcularea normei 1", Norma1},
						{"Calcularea normei infinit", Norma_infinit},
						{"Calcularea normei euclid", Norma_euclid}};
	int choice;
	printf("--------Meniu---------\n");
	printf("1.Norma 1\n");
	printf("2.Norma infinit\n");
	printf("3.Norma euclid\n");
	printf("Alegere >> ");
	scanf("%d", &choice);
	
	return m[choice - 1];
}

double Norma1(double **mat, int n, int m)
{
	double ans = 0, temp = 0;
	int i, j;

	for(j = 0;j < m;++j)
	{
		temp = 0;
		for(i = 0;i < n;++i)
		{
			temp += fabs(mat[i][j]);
		}
		if(temp > ans)
		{
			ans = temp;
		}
	}
	return ans;
}

double Norma_infinit(double **mat, int n, int m)
{
	double ans = 0, temp = 0;
	int i, j;

	for(i = 0;i < n;++i)
	{
		temp = 0;
		for(j = 0;j < m;++j)
		{
			temp += fabs(mat[i][j]);
		}
		if(temp > ans)
		{
			ans = temp;
		}
	}
	return ans;
}

double Norma_euclid(double **mat, int n, int m)
{
	double ans = 0;
	int i, j;
	
	for(i = 0;i < n;++i)
	{
		for(j = 0;j < m;++j)
		{
			ans += mat[i][j] * mat[i][j];
		}
	}

	return sqrt(ans);
}
