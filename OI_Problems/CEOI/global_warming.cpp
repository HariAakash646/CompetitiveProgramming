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

int inf = 1e9 + 5;

int main() {
    // usaco();
    int n, x;
    scd(n);
    scd(x);
    vi vec(n);
    frange(i, n) scd(vec[i]);

    vi inc(n+1, inf);
    inc[0] = -inf;
    vi cnt(n);
    frange(i, n) {
        int it = lower_bound(all(inc), vec[i]) - inc.begin();

        inc[it] = vec[i];
        cnt[i] = it;
    }
    vi dec;
    int ma = 0;
    for(int i=n-1; i>=0; i--) {
        int v = lower_bound(all(dec), -vec[i] + x) - dec.begin();
        ma = max(ma, cnt[i] + v);
        
        auto it = lower_bound(all(dec), -vec[i]) - dec.begin();
        if(it == dec.size()) dec.pb(-vec[i]);
        else dec[it] = -vec[i];
    }

    printf("%d", ma);
}