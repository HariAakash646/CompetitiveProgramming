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
    int n;
    scd(n);

    vi vec(n+1);

    frange(i, n) scd(vec[i+1]);

    vi li(n+1, n+2), ri(n+1, 0);

    forr(i, 1, n+1) {
        li[vec[i]] = min(i, li[vec[i]]);
        ri[vec[i]] = max(i, ri[vec[i]]);
    }

    vector<vector<pair<lli, lli>>> dp(n+1, vector<pair<lli, lli>>(n+1));

    forr(i, 1, n+1) {
        if(li[vec[i]] == i && ri[vec[i]] == i) dp[i][i] = mp(1, 0);
    }

    forr(l, 1, n+1) {
        for(int i=1; i+l<=n; i++) {
            int j = i + l;
            pair<lli, lli> p1, p2;
            p1.f = dp[i+1][j].s;
            p1.s = dp[i+1][j].f;

            p2.f = dp[i][j-1].s;
            p2.s = dp[i][j-1].f;

            if(li[vec[i]] == i && ri[vec[i]] <= j) p1.f++;
            if(ri[vec[j]] == j && li[vec[j]] >= i) p2.f++;
            dp[i][j] = max(p1, p2); 
        }
    } 
    printf("%d:%d", dp[1][n].f, dp[1][n].s);
}