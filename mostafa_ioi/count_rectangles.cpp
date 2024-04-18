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
        int n, q;
        scd(n);
        scd(q);
        vector<vll> pref(1001, vll(1001));

        frange(i, n) {
            lli h, w;
            sclld(h);
            sclld(w);
            pref[h][w] += h*w;
            // pref[i][j] %= mod;
        }

        forr(i, 1, 1001) {
            forr(j, 1, 1001) {
                pref[i][j] += pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
                // pref[i][j] %= mod;
            }
        }

        frange(i, q) {
            int hs, ws, hb, wb;
            scd(hs);
            scd(ws);
            scd(hb);
            scd(wb);
            hs++;
            ws++;
            hb--;
            wb--;
            printf("%lld\n", pref[hb][wb] - pref[hs-1][wb] - pref[hb][ws-1] + pref[hs-1][ws-1]);
        }
    }
}