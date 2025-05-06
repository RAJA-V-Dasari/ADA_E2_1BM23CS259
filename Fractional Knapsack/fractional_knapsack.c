#include<stdio.h>
#include<stdlib.h>

int partition(double arr[][3], int low, int high) {
    double pivot = arr[high][2];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j][2] > pivot) {
            i++;
            double temp0 = arr[i][0], temp1 = arr[i][1], temp2 = arr[i][2];
            arr[i][0] = arr[j][0];
            arr[i][1] = arr[j][1];
            arr[i][2] = arr[j][2];
            arr[j][0] = temp0;
            arr[j][1] = temp1;
            arr[j][2] = temp2;
        }
    }
    double temp0 = arr[i + 1][0], temp1 = arr[i + 1][1], temp2 = arr[i + 1][2];
    arr[i + 1][0] = arr[high][0];
    arr[i + 1][1] = arr[high][1];
    arr[i + 1][2] = arr[high][2];
    arr[high][0] = temp0;
    arr[high][1] = temp1;
    arr[high][2] = temp2;

    return i + 1;
}

void quick_sort(double arr[][3], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void fractional_knapsack(int v[], int w[], int n, int W) {
    double items[n][3];
    for (int i = 0; i < n; i++) {
        items[i][0] = v[i];
        items[i][1] = w[i];
        items[i][2] = (double)v[i] / (double)w[i];
    }

    quick_sort(items, 0, n - 1);

    double K = W;
    double total_val = 0.0;
    double x[n];
    for (int i = 0; i < n; i++) {
        x[i] = 0.0;
    }
    for (int i = 0; i < n && K > 0; i++) {
        if (items[i][1] <= K) {
            total_val += items[i][0];
            K -= items[i][1];
            x[i] = 1.0;
        } else {
            total_val += K * items[i][2];
            x[i] = K / items[i][1];
            K = 0;
        }
    }

    printf("Total Value: %f\n", total_val);
    printf("Item fractions: ");
    for (int i = 0; i < n; i++) {
        printf("%f ", x[i]);
    }
    printf("\n");
}

int main(){
    int n, W;

    printf("Enter capacity of knapsack: ");
    scanf("%d", &W);

    printf("Enter number of items: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of items.\n");
        return 0;
    }

    int v[n];
    int w[n];

    printf("Enter weights of items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter values of items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    fractional_knapsack(v, w, n, W);

    return 0;
}
