#ifndef HEADER_H_
#define HEADER_H_

#include <stdbool.h>

typedef struct Thunk
{
	bool finished;
	int n;
	long long temp;
	long long ans;
	struct Thunk (*next)(int, long long);	
} Thunk;

long long factorial(int n);
Thunk recursive(int n, long long aux);

#endif
