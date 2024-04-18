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
int n, v;
vvi graph;
vll vec;

vector<vll> dp1(n+1, vll(v+1)), dp2(n+1, vll(v+1));

lli ma = 0;

void dfs(int x, int p) {
    lli tot = 0;
    for(auto e : graph[x]) {
        if(e != p) tot += vec[e];
    }
    dp1[x][0] = 0;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x);
            ma = max(ma, dp1[e][v-1] + tot - vec[e] + vec[p]);
            ma = max(ma, dp2[e][v-1] + tot - vec[e] + vec[x] + vec[p]);
            
            forr(i, 1, v) {
                ma = max(ma, dp1[e][i] + dp2[x][(v-1)-i] + vec[p] - vec[e]);
                ma = max(ma, dp2[e][i] + dp1[x][(v-1)-i] + vec[p] - vec[e]);
            }

            forr(i, 1, v+1) {
                dp1[x][i] = max(dp1[x][i], dp1[e][i-1] + tot + vec[x] - vec[e]);
                dp2[x][i] = max(dp2[x][i], dp2[e][i-1] + tot + vec[x] - vec[e]);
                dp1[x][i] = max(dp1[x][i], dp1[x][i-1]);
                dp2[x][i] = max(dp2[x][i], dp2[x][i-1]);
            }
        }
    }
    forr(i, 1, v+1)
    {dp1[x][i] = max(dp1[x][i], tot + vec[x]);
        dp2[x][i] = max(dp2[x][i], tot);}
    printf("%d\n", x);
    forr(i, 1, v+1) printf("%lld %lld\n", dp1[x][i], dp2[x][i]);
}

int main() {
    usaco();
    scd(n);
    scd(v);

    graph = vvi(n+1);
    vec = vll(n+1);

    forr(i, 1, n+1) sclld(vec[i]);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    dp1 = dp2 = vector<vll>(n+1, vll(v+1, -1e17));

    dfs(1, 0);

    printf("%lld", ma);


}