#include <stdio.h>
#include <math.h>

// Function to calculate f(n)
int f(int n) {
    return 7 * n * n + 7 * n + 5;
}

int main() {
    int n0 = 1;
    double c1 = 7.0, c2 = 8.0; // c1 and c2 can be chosen around the coefficient of n^2

    // Find n0 such that for all n >= n0, c1 * g(n) <= f(n) <= c2 * g(n)
    while (!(c1 * n0 * n0 <= f(n0) && f(n0) <= c2 * n0 * n0)) {
        n0++;
    }

    printf("The value of n0 is: %d\n", n0);

    // Plot the values of f(n), c1 * g(n), and c2 * g(n) for n from 10 to 30
    printf("n\t f(n)\t c1 * g(n)\t c2 * g(n)\n");
    for (int n = 10; n <= 30; n++) {
        printf("%d\t %d\t %.2f\t %.2f\n", n, f(n), c1 * n * n, c2 * n * n);
    }

    return 0;
}
