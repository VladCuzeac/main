#include "header.h"

long long factorial(int n)
{
	Thunk f = recursive(n,1);
	while(!f.finished)
	{
		f = f.next(f.n, f.temp);
	}

	return f.ans;
}

Thunk recursive(int n, long long aux)
{
	Thunk f;
	if(n == 0)
	{
		f.finished = 1;
		f.ans = aux;
	}
	else
	{
		f.finished = 0;
		f.n = n - 1;
		f.temp = aux * n;
		f.next = recursive;
	}

	return f;
}
