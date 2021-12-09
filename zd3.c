#include<stdio.h>
#include<stdlib.h>
int main(void) {
    int *array = (int *)malloc(sizeof(int));
    int size = 0, capacity = 1, x;
    while (scanf("%d", &x) == 1 && x != 0) {
	if (size == capacity) {
	    capacity *= 2;
	    array = (int *)realloc(array, capacity*sizeof(int));
	}
	array[size++]=x;
    }
    for (int i=0;i<size;i+=2)
	printf("%d ",array[i]);
    for (int i=1;i<size;i+=2)
	printf("%d ",array[i]);
    printf("\n");
    free(array);
    return 0;
}
