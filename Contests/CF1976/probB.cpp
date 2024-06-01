#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
typedef long long int lli;
typedef vector<int> vi;

int main() {
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        vi v1(n), v2(n);
        int x;
        frange(i, n) scd(v1[i]);
        frange(i, n) scd(v2[i]);
        scd(x);
        lli tot = 1;
        lli v = 1e9+10;
        frange(i, n) {
            tot += abs(v1[i] - v2[i]);
            int a = min(v1[i], v2[i]);
            int b = max(v1[i], v2[i]);
            if(a <= x && x <= b) v = 0;
            v = min({v, (lli)abs(a-x), (lli)abs(b-x)});
        }
        tot += v;
        printf("%lld\n", tot);
    }
}