#include <stdio.h>

int f(int n) {
    return 7 * n + 5;
}

void plot_graph(int start, int end) {
    for (int n = start; n <= end; n++) {
        int fn = f(n);
        printf("n = %d, f(n) = %d\n", n, fn);
    }
}

int main() {
    int n0 = 1;
    int c = 7;
    
    printf("Proving that f(n) = 7n + 5 is O(n):\n");
    printf("Choosing c = %d and n0 = %d\n", c, n0);

    printf("Plotting graph for n from 1 to 10:\n");
    plot_graph(10, 30);
    
    return 0;
}
