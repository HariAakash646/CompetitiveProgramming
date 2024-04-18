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

vector<vii> graph;
vvi lift;
vi depth;
vi st, en;
vi id, edg;
int timer = 0;

void dfs(int x, int p) {
    lift[0][x] = p;
    depth[x] = depth[p]+1;
    st[x] = ++timer;
    id[timer] = x;
    for(auto e : graph[x]) {
        if(e.f != p) {
            dfs(e.f, x);
            edg[e.f] = e.s;
        }
    }
    en[x] = timer;
}

int binlift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) {
            x = lift[i][x];
        }
    }
    return x;
}

int lca(int u, int v) {
    if(depth[u] > depth[v]) swap(u, v);
    v = binlift(v, depth[v]-depth[u]);
    if(u == v) return u;

    for(int i=19; i>=0; i--) {
        int ut = lift[i][u];
        int vt = lift[i][v];
        if(ut != vt) {
            u = ut;
            v = vt;
        }
    }
    return lift[0][u];
}

bool cmp(int x, int y) {
    return st[x] < st[y];
}


int main() {
    // usaco();
    int n, m, k;
    scd(n);
    scd(m);
    scd(k);
    graph = vector<vii>(n+1);
    id = edg = st = en = depth = vi(n+1);
    lift = vvi(20, vi(n+1));

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(mp(b, i+1));
        graph[b].pb(mp(a, i+1));
    }

    dfs(1, 0);
    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    vi suf(n+1);

    frange(i, m) {
        int c;
        scd(c);
        vi vec(c);
        scd(vec[0]);
        
        forr(j, 1, c) {
            scd(vec[j]);
        }
        sort(all(vec), cmp);
        forr(j, 1, c) {
            int l = lca(vec[j], vec[j-1]);
            // printf("%d %d %d\n", vec[j], vec[j-1], l);
            suf[st[l]]-=1;
            // suf[st[vec[j-1]]]++;
            suf[st[vec[j]]]++;
        }
        // if(c > 2) {
            int l = lca(vec[0], vec[c-1]);
            // printf("%d %d %d\n", vec[0], vec[c-1], l);
            suf[st[vec[0]]]++;
            // suf[st[vec[c-1]]]++;
            suf[st[l]]-=1;
        // }
    }

    // printf("**********\n");

    vi out;

    for(int i=n; i>=1; i--) {
        // if(i < n) suf[i] += suf[i+1];

        // printf("%d %d %d\n", i, id[i], suf[i]);
        // suf[i]/=2;
        if(suf[i] >= k) out.pb(edg[id[i]]);
        suf[st[lift[0][id[i]]]] += suf[i];

    }

    printf("%d\n", (int)out.size());
    sort(all(out));
    for(auto e : out) printf("%d ", e);




}