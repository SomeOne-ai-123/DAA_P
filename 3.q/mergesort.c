#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1, n2 = right - mid;
    int L[n1], R[n2], i, j, k;

    for (i = 0; i < n1; i++) L[i] = arr[left + i];
    for (j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    for (i = 0, j = 0, k = left; k <= right; k++) {
        if (j >= n2 || (i < n1 && L[i] <= R[j])) arr[k] = L[i++];
        else arr[k] = R[j++];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n = 100000, arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++) arr[i] = rand();

    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    printf("Merge Sort executed in %f seconds\n", (double)(clock() - start) / CLOCKS_PER_SEC);

    return 0;
}