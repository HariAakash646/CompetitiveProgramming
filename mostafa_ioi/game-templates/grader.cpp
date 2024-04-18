#include <cstdio>
#include <cassert>
#include "game.h"

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}


int read_int() {
    int x;
    assert(scanf("%d", &x) == 1);
    return x;
}

int main() {
    usaco();
    int n, u, v;
    n = read_int();
    initialize(n);
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        u = read_int();
        v = read_int();
        printf("%d\n", hasEdge(u, v));
    }
    return 0;
}
