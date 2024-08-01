#include <stdio.h>
#include <math.h>

// Function to calculate f(n)
long f(int n) {
    return 8 * pow(n, 2) + 3 * pow(n, 3);
}

int main() {
    int n0 = 1;
    double c = 3.0; // c can be chosen to satisfy the condition

    // Find n0 such that for all n >= n0, f(n) <= c * g(n)
    while (f(n0) > c * pow(n0, 3)) {
        n0++;
    }

    printf("The value of n0 is: %d\n", n0);

    // Plot the values of f(n) and c * g(n) for n from 10 to 30
    printf("n\tf(n)\tc * g(n)\n");
    for (int n = 10; n <= 30; n++) {
        printf("%d\t%ld\t%.2f\n", n, f(n), c * pow(n, 3));
    }

    return 0;
}
