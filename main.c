#include<stdio.h>
int main()
{
	int t, n, l, a, b,closest;
	int totalen, start, sum;
	int *sx, *sy, *d;
	scanf("%d", &t);
	for(int a = 0; a < t; a++)
	{
		scanf("%d %d %d %d", &n, &l, &a, &b);
		sx = (int*)malloc(n * sizeof(int));
		sy = (int*)malloc(n * sizeof(int));
		d = (int*)malloc(n * sizeof(int));
		for(int b = 0; b < n; b++)
		{
			scanf("%d", &sx[b]);
			sy[b] = sx[b] + l;
		}
		totalen = n*l;
		for(int b = 0; b < n; b++)
		{
			start = start + sx[b];
		}
		start = start/n;
		if(start > a && start+totalen > b)
		{
			start = start - ((start+totalen)-b);
		}
		else if(start < a)
		{
			start = a;
		}
		else if(start > a && start+totalen < b){}
		for(int b = 0; b < n-1; b++)
		{
			if(abs(sx[b] - n) > abs(sx[b+1] - n))
			{
				closest = b+1;
			}
			else closest = b;
		}
	}
}
