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

int d, n;
vvi graph;
lli tot = 0;

lli dfs(int x, int p) {
    lli sz = 1;
    for(auto e : graph[x]) {
        if(e != p) sz += dfs(e, x);
    }
    tot += sz * (n-sz);
    // printf("%d %lld\n", x, tot);
    return sz;
}

int main() {
    // usaco();
    scd(n);
    scd(d);
    graph = vvi(n+1);
    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    int q;
    scd(q);

    frange(_, q) {
        int x;
        scd(x);
        // vi out = dfs(x, 0);
        tot = 0;
        dfs(x, 0);
        printf("%lld\n", tot);
    }
}