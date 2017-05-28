#include<stdio.h>
#include<stdlib.h>

int debug = 1;

int main()
{
	int t, n, l, a, b, A, B, sp, change;
	int totalen, start, sum, swap;
	int *sx, *sy;
	scanf("%d", &t);
	for(a = 0; a < t; a++)
	{
		scanf("%d %d %d %d", &n, &l, &A, &B);
		sx = (int*)malloc(n * sizeof(int));
		sy = (int*)malloc(n * sizeof(int));
		for(b = 0; b < n; b++)
		{
			scanf("%d", &sx[b]);
		}
		change = 1;
		while(change){
			for(b = 0; b < n; b++)
			{
				change = 0;
				if(sx[b] > sx[b-1])
					{
						swap = sx[b];
						sx[b] = sx[b-1];
						sx[b-1] = swap;
						change = 1;
					}
			}
		}
		for(b = 0; b < n; b++)
			{
			sy[b] = sx[b] + l;
			}
		totalen = n*l;
		for(b = 0; b < n; b++)
		{
			start = start + sx[b];
		}
		start = start/n;
		if(start > A && start+totalen > B)
		{
			start = start - ((start+totalen)-B);
		}
		else if(start < A)
		{
			start = A;
		}
		else if(start > A && start+totalen < B){}

		sp = start;
		if (debug) printf ("start = %d\n", start);
		for(int b = 0; b < n; b++)
		{
			sum  = sum + abs(sx[b]-sp);
			if (debug) printf ("snake at %d moves %d to %d\n", sx[b], abs(sx[b]-sp), sp);
			sp += l;
		}
		printf("%d\n", sum);
	}
}
