#include <stdio.h>

int f(int n) {
    return 5 * n * n + 6 * n + 3;
}

void plot_graph(int start, int end, int c1, int c2) {
    for (int n = start; n <= end; n++) {
        int fn = f(n);
        int c1gn = c1 * n * n;
        int c2gn = c2 * n * n;
        printf("n = %d, f(n) = %d, c1*g(n) = %d, c2*g(n) = %d\n", n, fn, c1gn, c2gn);
    }
}

int main() {
    int n0 = 10;
    int c1 = 4;
    int c2 = 6;

    printf("Proving that f(n) = 5n^2 + 6n + 3 is Theta(n^2):\n");
    printf("Choosing c1 = %d, c2 = %d, and n0 = %d\n", c1, c2, n0);

    printf("Plotting graph for n from 10 to 30:\n");
    plot_graph(10, 30, c1, c2);

    return 0;
}
