#include <stdio.h>

// Function to merge two subarrays and count inversions
int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;   // Starting index for left subarray
    int j = mid;    // Starting index for right subarray
    int k = left;   // Starting index to be sorted
    int inv_count = 0;

    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i);
        }
    }

    while (i <= mid - 1) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

// Function to use merge sort and count inversions
int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);
        inv_count += mergeAndCount(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

// Function to count inversions
int countInversions(int arr[], int n) {
    int temp[n];
    return mergeSortAndCount(arr, temp, 0, n - 1);
}

int main() {
    int user1[] = {3, 1, 2, 5, 4, 8, 6, 7};
    int user2[] = {4, 3, 2, 7, 8, 6, 5, 1};
    int user3[] = {1, 5, 3, 2, 8, 6, 4, 7};
    int n = 8;

    int inv1 = countInversions(user1, n);
    int inv2 = countInversions(user2, n);
    int inv3 = countInversions(user3, n);

    printf("User 1: %d inversions\n", inv1);
    printf("User 2: %d inversions\n", inv2);
    printf("User 3: %d inversions\n", inv3);

    int min_inversions = inv1;
    if (inv2 < min_inversions) min_inversions = inv2;
    if (inv3 < min_inversions) min_inversions = inv3;

    printf("Minimum inversions: %d\n", min_inversions);

    if (min_inversions == inv1) printf("Recommend User 1's playlist\n");
    else if (min_inversions == inv2) printf("Recommend User 2's playlist\n");
    else printf("Recommend User 3's playlist\n");

    return 0;
}
