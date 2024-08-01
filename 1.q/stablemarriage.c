
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 3

int menPreferences[N][N] = {
    {0, 1, 2}, // Man A's preferences (V, W, X)
    {1, 0, 2}, // Man B's preferences (W, V, X)
    {0, 2, 1}  // Man C's preferences (V, X, W)
};

int womenPreferences[N][N] = {
    {0, 1, 2}, // Woman V's preferences (A, B, C)
    {1, 0, 2}, // Woman W's preferences (B, C, A)
    {2, 0, 1}  // Woman X's preferences (C, A, B)
};

int currentPartner[N];
bool freeMen[N];

bool prefers(int woman, int man1, int man2) {
    for (int i = 0; i < N; i++) {
        if (womenPreferences[woman][i] == man1) return true;
        if (womenPreferences[woman][i] == man2) return false;
    }
    return false;
}

void stableMarriage() {
    memset(currentPartner, -1, sizeof(currentPartner));
    memset(freeMen, true, sizeof(freeMen));
    int freeCount = N;

    while (freeCount > 0) {
        int man;
        for (man = 0; man < N; man++) if (freeMen[man]) break;

        for (int i = 0; i < N && freeMen[man]; i++) {
            int woman = menPreferences[man][i];
            if (currentPartner[woman] == -1) {
                currentPartner[woman] = man;
                freeMen[man] = false;
                freeCount--;
            } else {
                int otherMan = currentPartner[woman];
                if (prefers(woman, man, otherMan)) {
                    currentPartner[woman] = man;
                    freeMen[man] = false;
                    freeMen[otherMan] = true;
                }
            }
        }
    }
}

int main() {
    stableMarriage();
    printf("Woman - Man\n");
    for (int i = 0; i < N; i++) {
        printf("%d       %d\n", i, currentPartner[i]);
    }
    return 0;
}
