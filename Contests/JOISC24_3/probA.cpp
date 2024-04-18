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

    vii vec(n);
    frange(i, n) {
        scd(vec[i].f);
        scd(vec[i].s);
    }

    vector<vector<map<int, seti>>> dp(n, vector<map<int, seti>>(n));
    frange(i, n) {
        dp[i][i][vec[i].f].insert(vec[i].s);
    }

    forr(l, 1, n) {
        for(int i=0; i+l<n; i++) {
            int r = i + l;
            for(int j=i+1; j<=r; j++) {
                for(auto p : dp[i][j-1]) {
                    for(auto e : dp[j][r]) {
                        for(auto x1 : p.s) {
                            for(auto x2 : e.s) {
                                dp[i][r][min(p.f, e.f)].insert(min(x1, x2));
                                dp[i][r][max(p.f, e.f)].insert(max(x1, x2));
                            }
                        }
                    }
                }
            }
        }
    }

    frange(i, m) {
        int l, r;
        scd(l);
        scd(r);
        if(dp[0][n-1][l].find(r) != dp[0][n-1][l].end()) printf("%d ", i+1);
    }
}