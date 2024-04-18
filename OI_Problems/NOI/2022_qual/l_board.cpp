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
    int n, m;
    scd(n);
    scd(m);
    vvi grid(n+2, vi(m+2));

    forr(i, 1, n+1) {
        forr(j, 1, m+1) {
            scd(grid[i][j]);
        }
    }

    vector<vll> prefh(n+2, vll(m+2)), sufh(n+2, vll(m+2));
    vector<vll> prefv(n+2, vll(m+2)), sufv(n+2, vll(m+2));

    vector<vll> pmih(n+2, vll(m+2)), smih(n+2, vll(m+2));
    vector<vll> pmiv(n+2, vll(m+2)), smiv(n+2, vll(m+2));
    forr(i, 1, n+1) {
        forr(j, 1, m+1) {
            prefh[i][j] = prefh[i][j-1] + grid[i][j];
            pmih[i][j] = min(pmih[i][j-1], prefh[i][j]);
        }
        for(int j=m; j>=1; j--) {
            sufh[i][j] = sufh[i][j+1] + grid[i][j];
            smih[i][j] = min(smih[i][j+1], sufh[i][j]);
        }
    }

    forr(j, 1, m+1) {
        forr(i, 1, n+1) {
            prefv[i][j] = prefv[i-1][j] + grid[i][j];
            pmiv[i][j] = min(pmiv[i-1][j], prefv[i][j]);
        }
        for(int i=n; i>=1; i--) {
            sufv[i][j] = sufv[i+1][j] + grid[i][j];
            smiv[i][j] = min(smiv[i+1][j], sufv[i][j]);
        }
    }

    lli ma = -1e18;

    forr(i, 1, n+1) {
        forr(j, 1, m+1) {
            lli v = max(prefh[i][j] - pmih[i][j-1], sufh[i][j] - smih[i][j+1]);
            v += max(prefv[i][j] - pmiv[i-1][j], sufv[i][j] - smiv[i+1][j]);
            v -= grid[i][j];
            ma = max(ma, v);
        }
    }
    printf("%lld", ma);
}