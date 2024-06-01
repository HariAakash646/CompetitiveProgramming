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

vvi graph;
vector<seti> black;
vi par, deg, col;
int cnt[4];

void dfs(int x, int p) {
    par[x] = p;
    for(auto e : graph[x]) {
        if(e != p) dfs(e, x);
    }
}

void upd(int x, int v) {
    if(deg[x] <= 2) cnt[deg[x]]--;
    else cnt[3]--;
    // printf("%d %d %d\n", x, deg[x], v);
    deg[x] = v;
    if(deg[x] <= 2) cnt[deg[x]]++;
    else cnt[3]++;
}

void ins(int x) {
    int p = par[x];
    col[x] = 1;
    deg[x] = 0;
    cnt[0]++;
    if(col[p]) {
        upd(p, deg[p]+1);
        if(black[p].size() <=1) {
            upd(x, deg[x]+1);
        }
        else if(black[p].size() == 2) {
            for(auto e : black[p]) {
                upd(e, deg[e]-1);
            }
        }
    }
    black[p].insert(x);
    if(black[x].size() <= 2) {
        for(auto e : black[x]) {
            upd(e, deg[e]+1);
        }
    }
    upd(x, deg[x] + black[x].size());
}

void rem(int x) {
    int p = par[x];
    col[x] = 0;
    if(deg[x] >= 3) cnt[3]--;
    else cnt[deg[x]]--;
    deg[x] = 0;
    black[p].erase(x);
    if(col[p]) {
        upd(p, deg[p]-1);
        if(black[p].size() == 2) {
            for(auto e : black[p]) {
                upd(e, deg[e]+1);
            }
        }
    }
    if(black[x].size()<=2) {
        for(auto e : black[x]) {
            upd(e, deg[e]-1);
        }
    }
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, q;
        scd(n);
        scd(q);
        par = deg = col = vi(n+1);
        vi colt(n+1);
        forr(i, 1, n+1) scd(colt[i]);

        frange(i, 4) cnt[i] = 0;

        graph = vvi(n+1);
        black = vector<seti>(n+1);

        frange(i, n-1) {
            int a, b;
            scd(a);
            scd(b);
            graph[a].pb(b);
            graph[b].pb(a);
        }

        dfs(1, 0);

        forr(i, 1, n+1) {
            if(colt[i]) ins(i);
        }

        frange(i, q) {
            int u;
            scd(u);
            if(col[u]) {
                rem(u);
            }
            else ins(u);
            // frange(j, 4) printf("%d ", cnt[j]);
            if((cnt[3] + cnt[0] == 0 && cnt[1] == 2) || (cnt[0] + cnt[1] + cnt[2] + cnt[3] == 1)) {
                printf("YES\n");
            }
            else printf("NO\n");
        }
    }
}