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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

vii out;
vector<vector<pair<lli, int>>> dp;
vll vec;

void rec(int id, int x) {
    if(x == 0) {
        if(vec[id] != 0)
            out.pb(mp(id, id));
        return;
    }
    rec(id, x-1);
    out.pb(mp(id-(x-1), id));
    forr(i, id-(x-1), id+1) vec[i] = x;
    rec(id-1, x-1);
}

void process(int l, int r) {
    if(l > r) return;
    int mid = dp[l][r].s;

    if(mid < l) return;

    if(mid == r) {
        rec(mid, r-l);
        out.pb(mp(l, r));
        return;
    }
    process(l, mid);
    process(mid+1, r);
}

int main() {
    // usaco();
    int n;
    scd(n);

    vec = vll(n);
    frange(i, n) sclld(vec[i]);

    dp = vector<vector<pair<lli, int>>>(n, vector<pair<lli, int>>(n));

    frange(i, n) {
        dp[i][i] = max(mp(vec[i], i-1), mp(1LL, i));
    }

    forr(i, 1, n) {
        for(int j=0; j+i<n; j++) {
            int r = j+i;
            pair<lli, int> ma = mp((i+1)*(i+1), r);
            dp[j][r] = ma;
            for(int k=j; k<r; k++) {
                dp[j][r] = max(dp[j][r], mp(dp[j][k].f + dp[k+1][r].f, k));
            }
        }
    }

    printf("%lld ", dp[0][n-1].f);
    process(0, n-1);

    printf("%d\n", (int)out.size());
    for(auto p : out) printf("%d %d\n", p.f+1, p.s+1);


}