#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITERATIONS 5

// Precompute All Method
void precomputeAll(int arr[], int size) {
    int *precomputedMin = (int *)malloc(size * sizeof(int));
    precomputedMin[0] = arr[0];
    for (int i = 1; i < size; i++) {
        precomputedMin[i] = (arr[i] < precomputedMin[i - 1]) ? arr[i] : precomputedMin[i - 1];
    }
    
    // Query using precomputed minimums
    int min_val = precomputedMin[size - 1];
    printf("Precompute All: Min value between 0 and %d is %d\n", size - 1, min_val);

    free(precomputedMin);
}

// Blocking Method (Block processing)
void blocking(int arr[], int size) {
    int blockSize = 100;  // Example block size for blocking method
    int min_val = arr[0];
    
    for (int i = 0; i < size; i += blockSize) {
        int blockMin = arr[i];
        for (int j = i; j < i + blockSize && j < size; j++) {
            if (arr[j] < blockMin) {
                blockMin = arr[j];
            }
        }
        if (blockMin < min_val) {
            min_val = blockMin;
        }
    }
    printf("Blocking: Min value between 0 and %d is %d\n", size - 1, min_val);
}

// Sparse Table Method
void sparseTable(int arr[], int size) {
    int log = 1;
    while ((1 << log) <= size) log++;

    int **st = (int **)malloc(log * sizeof(int *));
    for (int i = 0; i < log; i++) {
        st[i] = (int *)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        st[0][i] = arr[i];
    }

    for (int j = 1; j < log; j++) {
        for (int i = 0; i + (1 << j) <= size; i++) {
            st[j][i] = (st[j - 1][i] < st[j - 1][i + (1 << (j - 1))]) ? st[j - 1][i] : st[j - 1][i + (1 << (j - 1))];
        }
    }

    int left = 0, right = size - 1;
    int min_val = arr[left];
    for (int j = log - 1; j >= 0; j--) {
        if (left + (1 << j) <= right) {
            min_val = (min_val < st[j][left]) ? min_val : st[j][left];
            left += (1 << j);
        }
    }

    printf("Sparse Table: Min value between 0 and %d is %d\n", size - 1, min_val);

    for (int i = 0; i < log; i++) {
        free(st[i]);
    }
    free(st);
}

// Precompute None Method (Brute force without preprocessing)
void precomputeNone(int arr[], int size) {
    int min_val = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    printf("Precompute None: Min value between 0 and %d is %d\n", size - 1, min_val);
}

// Main function to run tests
int main() {
    int testSizes[] = {400, 1600, 3200, 6400, 12800, 25600, 51200, 102400};
    int numTests = sizeof(testSizes) / sizeof(testSizes[0]);
    srand(time(NULL));

    for (int i = 0; i < MAX_ITERATIONS; i++) {
        for (int j = 0; j < numTests; j++) {
            int size = testSizes[j];
            int *arr = (int *)malloc(size * sizeof(int));

            // Fill array with random numbers between 0 and 999
            for (int k = 0; k < size; k++) {
                arr[k] = rand() % 1000;
            }

            // Measure execution time for Precompute All
            clock_t start = clock();
            precomputeAll(arr, size);
            clock_t end = clock();
            printf("Precompute All Time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

            // Measure execution time for Blocking
            start = clock();
            blocking(arr, size);
            end = clock();
            printf("Blocking Time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

            // Measure execution time for Sparse Table
            start = clock();
            sparseTable(arr, size);
            end = clock();
            printf("Sparse Table Time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

            // Measure execution time for Precompute None
            start = clock();
            precomputeNone(arr, size);
            end = clock();
            printf("Precompute None Time: %.6f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

            // Free allocated memory
            free(arr);
        }
    }

    return 0;
}
