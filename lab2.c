#include <stdio.h>

#define max_s 100
#define max_len 1000

int s[max_s];
int seq[max_len];
int m;
int n;

void find(int idx, int sum, int prev) {
    if (sum == n) {
        printf("[");
        for (int i = 0; i < idx; i++) {
            printf("%d", seq[i]);
            if (i < idx - 1) printf(", ");
        }
        printf("]\n");
        return;
    }

    for (int i = 0; i < m; i++) {
        if (s[i] == prev) continue;
        if (sum + s[i] > n) continue;

        seq[idx] = s[i];
        find(idx + 1, sum + s[i], s[i]); //rec
    }
}

int main() {
    printf("n = ");
    scanf("%d", &n);

    printf("m = ");
    scanf("%d", &m);

    printf("s:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &s[i]);
    }

    find(0, 0, 0);

    return 0;
}
