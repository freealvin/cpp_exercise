#include "holand.h"

void
swap(int balls[], int x, int y){
	int temp = balls[x];
	balls[x] = balls[y];
	balls[y] = temp;
}

void
sort_balls(int balls[], int n){
	int begin = 0;
	int current = 0;
	int end = n - 1;
	int temp;
	while ( current <= end && end >= 0 ){
		#ifdef DEBUG
		printf("begin= %d, current = %d, end = %d\n", begin, current, end);
		#endif
		
		if ( 0 == balls[current] ){
			swap(balls, current, begin);
			current += 1;
			begin += 1;
		} else if ( 2 == balls[current] ){
			swap(balls, current, end);
			end -= 1;
		} else {
			current += 1;
		}
	}
}

void
display(int balls[], int n){
	int i;
	for (  i = 0; i < n-1; i += 1){
		printf("%d ", balls[i]);
	}
	
	printf("%d\n", balls[n-1]);
}