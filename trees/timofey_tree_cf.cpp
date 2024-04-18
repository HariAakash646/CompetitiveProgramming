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

vvi graph;
int mi;
vi dist;

void dfs(int x, int p) {
    if(dist[x] >= mi) return;
    for(auto e : graph[x]) {
        if(e != p) {
            if(dist[x] + 1 < dist[e]) {
                dist[e] = dist[x] + 1;
                dfs(e, x);
            }
            else mi = min(mi, dist[x]+ dist[e] + 1);
        }
    }
}

int main() {
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n, c0;
        scd(n);
        scd(c0);
        dist = vi(n+1, 1e9);
        dist[c0] = 0;
        mi = n;
        vi val(n-1);
        frange(i, n-1) scd(val[i]);
        graph = vvi(n+1);
        frange(i, n-1) {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }

        dfs(c0, 0);

        for(auto e : val) {
            dist[e] = 0;
            dfs(e, 0);
            printf("%d\n", mi);
        }
    }
}