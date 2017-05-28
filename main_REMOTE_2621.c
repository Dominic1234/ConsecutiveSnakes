#include<stdio.h>
#include<stdlib.h>

int debug = 0;

int main()
{
	int t, n, l, a, b, A, B, sp, change;
	int totalen, start, sum, swap;
	int mid;
	int *sx, *sy;
	scanf("%d", &t);
	for(a = 0; a < t; a++)
	{
		sp = 0;
		sum = 0;
		start = 0;
		scanf("%d %d %d %d", &n, &l, &A, &B);
		sx = (int*)malloc(n * sizeof(int));
		sy = (int*)malloc(n * sizeof(int));
		for(b = 0; b < n; b++)
		{
			scanf("%d", &sx[b]);
		}
		change = 1;
		while(change){
			for(b = 1; b < n; b++)
			{
				change = 0;
				if(sx[b] < sx[b-1])
					{
						swap = sx[b];
						sx[b] = sx[b-1];
						sx[b-1] = swap;
						change = 1;
					}
			}
		}
		if (debug) {
			for(b = 0; b < n; b++) {
				printf ("%d ", sx[b]);
		    	}
			printf ("\n");
		}
		for(b = 0; b < n; b++)
			{
			sy[b] = sx[b] + l;
			}
		totalen = n*l;
		if(n%2 !=0)
		{
			mid  = sx[(n+1)/2-1];

		}
		else
		{
			mid = (sx[n/2-1]+sx[(n+2)/2-1])/2;
		}
		if (debug) printf ("mid = %d\n", mid);
		if(A > mid-(l*(n/2)))
		{
			start = A;
			if (debug) printf ("Adjusting start due to left overlap. New = %d\n", start);
		}
		else if(B < mid+((n+1)/2*l))
		{
			start = mid-(n/2*l) - (mid+((n+1)/2*l) - B);
			if (debug) printf ("Adjusting start due to right overlap. New = %d\n", start);
		}
		else
		{
			start = mid-(n/2*l);
		}
		sp = start;
		if (debug) printf ("start = %d\n", start);
		for(b = 0; b < n; b++)
		 {
		 sum  = sum + abs(sx[b]-sp);
		 if (debug) printf ("snake at %d moves %d to %d\n", sx[b], abs(sx[b]-sp), sp);
		 	sp += l;
		}
		if (debug) printf ("=== Answer = ");
		printf("%d\n", sum);
			free(sx);
			free(sy);
	}
}
