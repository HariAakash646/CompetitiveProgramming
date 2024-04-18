#include "boxes.h"
#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;



long long delivery(int n, int k, int l, int pos[]) {
    vll dp1(n+1), dp2(n+2);
    sort(pos, pos+n);
    forr(i, 1, n+1) {
        dp1[i] = dp1[max(0, i-k)] + min(pos[i-1]*2, l);
    }

    for(int i=n; i>=1; i--) {
        dp2[i] = dp2[min(n+1, i+k)] + min((l-pos[i-1]) * 2, l);
    }

    lli mi = 1e18;
    frange(i, n+1) {
        mi = min(mi, dp1[i] + dp2[i+1]);
    }
    return mi;
}
