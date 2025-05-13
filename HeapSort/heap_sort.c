#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int l = 2 * i + 1, r = 2 * i + 2, m = i;
    if (l < n && arr[l] > arr[m]) m = l;
    if (r < n && arr[r] > arr[m]) m = r;
    if (m != i) {
        int t = arr[i];
        arr[i] = arr[m];
        arr[m] = t;
        heapify(arr, n, m);
    }
}

void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapify(arr, i, 0);
    }
}

void prnt(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    heapsort(arr, n);
    printf("Sorted array is: \n");
    prnt(arr, n);

    return 0;
}
