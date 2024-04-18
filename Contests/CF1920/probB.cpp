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
    int t;
    scd(t);
    frange(_, t) {
        int n, k, x;
        scd(n);
        scd(k);
        scd(x);

        vll vec(n+1);
        vll pref(n+1);

        forr(i, 1, n+1) {
            sclld(vec[i]);
        }
        sort(all(vec));
        forr(i, 1, n+1) {
            pref[i] = pref[i-1] + vec[i];
        }
        lli ma = -1e16;
        for(int i=n; i>=n-k; i--) {
            lli v = -(pref[i] - pref[max(0, i-x)]);
            v += pref[max(0, i-x)];
            ma = max(ma, v);
        }
        printf("%lld\n", ma);

    }
}