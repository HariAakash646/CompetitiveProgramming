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


void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main() {
    // usaco();
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);

    vi v1(n+1), v2(m+1);
    forr(i, 1, n+1) scd(v1[i]);
    forr(i, 1, m+1) scd(v2[i]);

    vi val(n+1);
    forr(i, 1, n+1) {
        if(v1[i] == 0) val[i] = 0;
        else val[i] = val[i-1] + 1;
    }

    sort(all(val));

    vi val2(m+1);
    vi fac;

    for(int j=1; j*j<=k; j++) {
        if(k % j == 0) {
            fac.pb(j);
            if(j != k/j) fac.pb(k/j);
        }
    }
    sort(all(fac));
    lli tot = 0;
    forr(i, 1, m+1) {
        if(v2[i] == 0) val2[i] = 0;
        else val2[i] = val2[i-1] + 1;
        for(auto e : fac) {
            if(e > val2[i]) break;
            auto it = lower_bound(all(val), k/e);
            tot += val.end() - it;
        }
    }
    printf("%lld", tot);
}