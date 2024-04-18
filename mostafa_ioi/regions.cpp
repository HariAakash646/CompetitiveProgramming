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

int n, r, q;
vvi regions, graph;
vi pos, idx;
vvi val;
int cnt = 0;
vi st, en;
int timer = 0;
vvi euler;
vi vec;

void dfs(int x) {
    st[x] = ++timer;
    euler[pos[x]].pb(st[x]);
    frange(i, vec.size()) {
        val[i][pos[x]] += vec[i];
    }
    
    if(idx[pos[x]] != -1) {
        vec[idx[pos[x]]]++;
    }
    for(auto e : graph[x]) {
        
        dfs(e);
        
    }
    if(idx[pos[x]] != -1) {
        vec[idx[pos[x]]]--;
    }
    en[x] = timer;
}


int main() {
    // usaco();
    scd(n);
    scd(r);
    scd(q);

    graph = vvi(n+1);
    regions = vvi(r+1);
    pos = vi(n+1);

    scd(pos[1]);
    regions[pos[1]].pb(1);

    forr(i, 2, n+1) {
        int p, h;
        scd(p);
        scd(h);
        regions[h].pb(i);
        graph[p].pb(i);
        pos[i] = h;
    }
    int sq = sqrt(n);
    idx = vi(r+1, -1);
    forr(i, 1, r+1) {
        if(regions[i].size() >= sq) {
            idx[i] = val.size();
            val.pb(vi(n+1));
        }
    }
    st = en = vi(n+1);
    euler = vvi(r+1);
    vec = vi(val.size());
    dfs(1);

    frange(_, q) {
        int r1, r2;
        scd(r1);
        scd(r2);
        if(idx[r1] != -1) {
            printf("%d\n", val[idx[r1]][r2]);
        }
        else {
            // printf("man %d\n", r1);
            int tot = 0;
            for(auto e : regions[r1]) {
                tot += upper_bound(all(euler[r2]), en[e]) - lower_bound(all(euler[r2]), st[e]);
            }
            printf("%d\n", tot);
        }
        fflush(stdout);
    }
}