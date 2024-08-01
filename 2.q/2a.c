#include <stdio.h>
#include <math.h>

// Function to calculate f(n)
int f(int n) {
    return 3 * n * n + 4 * n + 3;
}

int main() {
    int n0 = 1;
    double c = 1.0; // c can be a small constant

    // Find n0 such that for all n >= n0, f(n) >= c * g(n)
    while (f(n0) < c * n0) {
        n0++;
    }

    printf("The value of n0 is: %d\n", n0);

    // Plot the values of f(n) and c * g(n) for n from 10 to 30
    printf("n\t f(n)\t c * g(n)\n");
    for (int n = 10; n <= 30; n++) {
        printf("%d\t%d\t%.2f\n", n, f(n), c * n);
    }

    return 0;
}

