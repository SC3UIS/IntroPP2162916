/*

     * C Program to Implement Postman Sort Algorithm

  Purpose:

    Este es un código que demuestra la implementación y paralelización usando metodos OpenMP

  Example:

    22 March 2024 03:00:0 AM

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    22 March 2024

  Author:
  Deivyd Dario Parra. 
  OpenMP Modification:
  22 March 2024 by Deivyd Parra, Universidad Industrial de Santander.                    
  This OpenMP Modification makes a parallelization of the original Code...  
*/

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

void arrange(int start, int end);
int generateRandom();

int array[100000], array1[100000];
int count;

int main() {
    int i, j, temp, max, maxdigits = 0, c = 0;
    int n = 1;
    int t1;

    printf("Enter size of array: ");
    scanf("%d", &count);

    srand(time(NULL));  // Initialize the random number generator

    double start_time = omp_get_wtime(); // Start the timer

    // Generate random numbers and store them in array1 and array
    #pragma omp parallel for shared(array1, array) private(i)
    for (i = 0; i < count; i++) {
        array1[i] = generateRandom();
        array[i] = array1[i];
    }

    // Calculating the number of significant digits in parallel
    #pragma omp parallel for private(i, c) shared(maxdigits)
    for (i = 0; i < count; i++) {
        int t = array[i];
        while (t > 0) {
            c++;
            t /= 10; // Find MSB
        }
        #pragma omp critical
        {
            if (maxdigits < c) {
                maxdigits = c;
            }
        }
        c = 0;
    }

    while (--maxdigits) {
        n *= 10;
    }

    // Sorting based on the most significant digit
    for (i = 0; i < count; i++) {
        max = array[i] / n;
        int t = i;
        for (j = i + 1; j < count; j++) {
            if (max > (array[j] / n)) {
                max = array[j] / n;
                t = j;
            }
        }
        temp = array1[t];
        array1[t] = array1[i];
        array1[i] = temp;
        temp = array[t];
        array[t] = array[i];
        array[i] = temp;
    }

    // Sorting numbers with the same most significant digit
    while (n >= 1) {
        for (i = 0; i < count;) {
            t1 = array[i] / n;
            for (j = i + 1; t1 == (array[j] / n); j++);
            arrange(i, j);
            i = j;
        }
        n /= 10;
    }

    double end_time = omp_get_wtime(); // Stop the timer

    // Printing the sorted array
    printf("\nSorted Array (Postman sort): ");
    for (i = 0; i < count; i++) {
        printf("%d ", array1[i]);
    }
    printf("\n");

    // Calculate and print the execution time
    printf("Execution time: %.6f seconds\n", end_time - start_time);

    return 0;
}

/* Function to arrange the sequence having the same most significant digit */
void arrange(int start, int end) {
    int i, j, temp;
    for (i = start; i < end - 1; i++) {
        for (j = i + 1; j < end; j++) {
            if (array1[i] > array1[j]) {
                temp = array1[i];
                array1[i] = array1[j];
                array1[j] = temp;
                temp = (array[i] % 10);
                array[i] = (array[j] % 10);
                array[j] = temp;
            }
        }
    }
}

/* Function to generate a random number between 0 and 9999 */
int generateRandom() {
    int number = rand() % 10000;
    return number;
}
