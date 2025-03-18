#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void main(){
    int array[10] = {646,29,683,246,918,179,613,970,44,545};
    int len = sizeof(array) / sizeof(array[0]);

    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    clock_t start = clock();
    quick_sort(array, 0, len - 1);
    clock_t end = clock();

    printf("\nSorted array:\n");
    for (int i = 0; i < len; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.10f seconds\n", seconds);


}

