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

pii diam(int x, int p) {
    pii out = mp(0, x);
    for(auto e : graph[x]) {
        if(e != p) {
            pii p1 = diam(e, x);
            p1.f++;
            out = max(out, p1);
        }
    }
    return out;
}

vvi lift1, lift2;
vi dep1, dep2;

void dfs(int x, int p, int d, vvi &lift, vi &dep) {
    dep[x] = d;
    lift[0][x] = p;
    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x, d+1, lift, dep);
        }
    }
}

int binlift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) {
            x = lift1[i][x];
        }
    }
    return x;
}

int main() {
    // usaco();
    int n;
    scd(n);
    graph = vvi(n+1);
    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    int d1 = diam(1, 0).s;
    int d2 = diam(d1, 0).s;

    lift1 = lift2 = vvi(20, vi(n+1));
    dep1 = dep2 = vi(n+1);

    dfs(d1, 0, 0, lift1, dep1);
    dfs(d2, 0, 0, lift2, dep2);

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift1[i][j] = lift1[i-1][lift1[i-1][j]];
            lift2[i][j] = lift2[i-1][lift2[i-1][j]];
        }
    }

    int q;
    scd(q);
    // printf("%d %d\n", d1, d2);
    // forr(i, 1, n+1) {
    //     printf("%d %d\n", dep1[i], dep2[i]);
    // }
    frange(_, q) {
        int u, k;
        scd(u);
        scd(k);
        if(dep2[u] > dep1[u]) {
            swap(dep1, dep2);
            swap(lift1, lift2);
        }
        if(dep1[u] < k) printf("-1\n");
        else printf("%d\n", binlift(u, k));
    }

}