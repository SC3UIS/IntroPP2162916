#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void binarySearch(int *, int, int, int, int);
void bubbleSort(int *, int);

int main() {
    const int n = 100000;
    int key, i;
    int *list = (int *)malloc(n * sizeof(int));
    clock_t start, end;
    double cpu_time_used;

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        list[i] = rand() % 1000; // Genera números aleatorios entre 0 y 999
    }

    start = clock();
    bubbleSort(list, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo tomado para ordenar la lista: %lf seconds\n", cpu_time_used);

    printf("Ingrese el valor a buscar: ");
    scanf("%d", &key);

    start = clock();
    binarySearch(list, 0, n - 1, key, 0);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Tiempo tomado para buscar en lista ordenada: %lf seconds\n", cpu_time_used);

    free(list);
    return 0;
}

void bubbleSort(int *list, int size) {
    int temp, i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (list[j] > list[j + 1]) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void binarySearch(int *list, int lo, int hi, int key, int rank) {
    int mid;

    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (list[mid] == key) {
            printf("Element found\n");
            return;
        } else if (list[mid] < key) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    printf("Element not found\n");
}

