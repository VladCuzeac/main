#include <stdio.h>
#include "header.h"

int main(void)
{
	int n, i, j;
	double temp;
	double (*aria[3])(double, double, int, double (*)(double)) = {Trapez, Dreptunghi, Simpson};
	double (*functii[5])(double) = {I1, I2, I3, I4, I5};
	double limite[5][2] = {{0,1}, {1,3},{0,3},{1,4},{1,5}};
	
	printf("Numarul de diviziuni:");
	scanf("%d",&n);
	
	printf("Nr:\tTrapez\t\tDreptunghi\tSimpson\n");
	for(i = 0;i < 5;i++)
	{
		printf("I%d\t", i + 1);
		for(j = 0;j < 3;++j)
		{
			temp = (*aria[j])(limite[i][0], limite[i][1], n, (*functii[i]));
			printf("%.4lf\t\t", temp);
		}
		printf("\n");
	}

	return 0;
}
