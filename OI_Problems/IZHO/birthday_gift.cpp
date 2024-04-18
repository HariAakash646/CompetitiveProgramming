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
vi depth;
vvi lift;

void dfs(int x, int p, int d) {
    lift[x][0] = p;
    depth[x] = d;

    for(auto e : graph[x]) {
        if(e != p) {
            dfs(e, x, d+1);
        }
    }
}

int binlift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) {
            x = lift[x][i];
        }
    }
    return x;
}

int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);

    v = binlift(v, depth[v] - depth[u]);

    if(v == u) return u;

    for(int i=19; i>=0; i--) {
        int ut = lift[u][i];
        int vt = lift[v][i];
        if(ut != vt) {
            u = ut;
            v= vt;
        }
    }
    return lift[u][0];
}

int main() {
    // usaco();
    int n, m, q;
    scd(n);
    scd(m);
    scd(q);
    graph = vvi(n+1);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
        graph[b].pb(a);
    }

    depth = vi(n+1);
    lift = vvi(n+1, vi(20));

    dfs(1, 0, 0);

    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift[j][i] = lift[lift[j][i-1]][i-1];
        }
    }

    vi vec(m+1);

    vector<seti> one(n+1), two(n+1);

    forr(i, 1, m+1) {
        int a;
        scd(a);
        vec[i] = a;
        one[a].insert(i);
        if(i > 1) {
            int l = lca(vec[i], vec[i-1]);
            two[l].insert(i-1);
        }
    }

    frange(_, q) {
        int t;
        scd(t);
        if(t == 1) {
            int pos, v;
            scd(pos);
            scd(v);
            // printf("%d %d %d\n", t, pos, v);
            one[vec[pos]].erase(pos);
            one[v].insert(pos);

            if(pos > 1) {
                int l = lca(vec[pos], vec[pos-1]);
                two[l].erase(pos-1);
                l = lca(v, vec[pos-1]);
                two[l].insert(pos-1);
            }
            if(pos < m) {
                int l = lca(vec[pos], vec[pos+1]);
                two[l].erase(pos);
                l = lca(v, vec[pos+1]);
                two[l].insert(pos);
            }
            vec[pos] = v;
        }
        else {
            int l, r, v;
            scd(l);
            scd(r);
            scd(v);
            auto it = one[v].lower_bound(l);
            if(it != one[v].end()) {
                if(*it <= r) {
                    printf("%d %d\n", *it, *it);
                    continue;
                }
            }
            auto it2 = two[v].lower_bound(l);
            if(it2 != two[v].end()) {
                if(*it2 < r) {
                    printf("%d %d\n", *it2, (*it2)+1);
                    continue;
                }
            }
            printf("-1 -1\n");
        }
    }

}