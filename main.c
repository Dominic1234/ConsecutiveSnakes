#include<stdio.h>
#include<stdlib.h>

int debug = 1;

int main()
{
	long long t, n, l, a, b, A, B, sp, change;
	long long start, sum, swap;
	int mid;
	int *sx, *sy;
	scanf("%lld", &t);
	for(a = 0; a < t; a++)
	{
		sp = 0;
		sum = 0;
		start = 0;
		scanf("%lld %lld %lld %lld", &n, &l, &A, &B);
		sx = (int*)malloc(n * sizeof(int));
		sy = (int*)malloc(n * sizeof(int));
		for(b = 0; b < n; b++)
		{
			scanf("%d", &sx[b]);
		}
		change = 1;
		while(change){
			change = 0;
			for(b = 1; b < n; b++)
			{
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
		if(n%2 !=0)
		{
			mid  = sx[(n+1)/2-1];

		}
		else
		{
			mid = (sy[n/2-1]+sx[(n+2)/2-1])/2;
		}
		if (debug) printf ("mid = %d\n", mid);
		if(A > mid-(l*(n/2)))
		{
			start = A;
			if (debug) printf ("Adjusting start due to left overlap. New = %lld\n", start);
		}
		else if(B < mid+((n+1)/2*l))
		{
			start = mid-(n/2*l) - (mid+((n+1)/2*l) - B) + 1;
			if (debug) printf ("Adjusting start due to right overlap. New = %lld\n", start);
		}
		else
		{
			start = mid-(n/2*l);
		}
		sp = start;
		if (debug) printf ("start = %lld\n", start);
		for(b = 0; b < n; b++)
		 {
		 sum  = sum + abs(sx[b]-sp);
		 if (debug) printf ("snake at %lld moves %lld to %lld\n", sx[b], abs(sx[b]-sp), sp);
		 	sp += l;
		}
		if (debug) printf ("=== Answer = ");
		printf("%lld\n", sum);
			free(sx);
			free(sy);
	}
}
