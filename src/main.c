/* hello.c */
#include <stdio.h>
#include <stdlib.h>

int ones_count(int number){
    int count = 0;
    while (number > 0) {
        if (number % 2 == 1) {
            ++count;
        }
        number >>= 1;
    }
    
    return count;
}

int comp (const int *i, const int *j) {
    return ones_count(*i) - ones_count(*j);
}

int main (int argc, char** argv) {
	if (argc < 2) {
        printf("Needs more arguments\n");
        return 1;
    }
    char* ptr;
    int arr_size = strtol(argv[1], &ptr, 10);
    int *arr = malloc(arr_size * sizeof(int));
    for(int i = 0; i < arr_size; ++i) {
        arr[i] = i;
    }
    for(int i = 0; i < arr_size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    for(int i = 0; i < arr_size; ++i) {
        printf("%d ", ones_count(arr[i]));
    }
    qsort(arr, 10, sizeof (int), (int(*) (const void *, const void *)) comp);
    printf("\n");
    printf("\n");
    for(int i = 0; i < arr_size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    for(int i = 0; i < arr_size; ++i) {
        printf("%d ", ones_count(arr[i]));
    }
    printf("\n");
    
    free(arr);
    
    return 0;
}
