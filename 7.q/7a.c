#include <stdio.h>

int f(int n) {
    return 8 * n * n + 3 * n + 3;
}

void plot_graph(int start, int end, int c) {
    for (int n = start; n <= end; n++) {
        int fn = f(n);
        int cgn = c * n * n;
        printf("n = %d, f(n) = %d, c*g(n) = %d\n", n, fn, cgn);
    }
}

int main() {
    int n0 = 10;
    int c = 9;

    printf("Proving that f(n) = 8n^2 + 3n + 3 is Theta(n^2):\n");
    printf("Choosing c = %d and n0 = %d\n", c, n0);

    printf("Plotting graph for n from 10 to 30:\n");
    plot_graph(10, 30, c);

    return 0;
}
