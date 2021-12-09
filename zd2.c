#include <stdio.h>
#include <stdlib.h>


long tracprof(int size, int *matrix) {
	int i; 
	long sum = 0;
	for (i = 0; i<size; i++)
		sum+=*(matrix+i+i*size);
	return sum;
}

int main(void) {
	int n, i, j, k, size, size_max_matrix =0;
	long tr_sum, max = 0;
	int *matrix;
	int *max_matrix=NULL;
	scanf("%d", &n);
	for (i = 0; i<n; i++) {
		scanf("%d", &size);
		matrix = (int*)calloc(size*size,sizeof(int));
		for (k = 0; k<size; k++)	
			for (j = 0; j<size; j++)
				scanf("%d", matrix+j+k*size);
			
		tr_sum = tracprof(size, matrix);
		if (tr_sum>max) {
			free(max_matrix);
			max = tr_sum;
			max_matrix = matrix;
			size_max_matrix = size;

		}
		else {
			free(matrix);
		}
	}
		for (k = 0; k<size_max_matrix; k++, putchar('\n')) 
			for (j = 0; j<size_max_matrix; j++)
				printf("%d ", *(max_matrix+j+k*size_max_matrix));
}
