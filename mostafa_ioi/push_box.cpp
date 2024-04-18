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

int n, m, q;
vvi grid;
vvi pos;
vector<vi> num, lowpt;
stack<pair<pii, pii>> stk;
vector<vii> comps;
int timer = 0;

void dfs(pii x, pii y) {
    num[y.f][y.s] = ++timer;
    lowpt[y.f][y.s] = num[y.f][y.s];
    vii nex;
    nex.pb(mp(y.f+1, y.s));
    nex.pb(mp(y.f-1, y.s));
    nex.pb(mp(y.f, y.s+1));
    nex.pb(mp(y.f, y.s-1));
    for(auto p : nex) {
        if(p.f < 0 || p.f >= n || p.s < 0 || p.s >= m || grid[p.f][p.s]) continue;
        if(p != x) {
            if(num[p.f][p.s]) {
                lowpt[y.f][y.s] = min(lowpt[y.f][y.s], num[p.f][p.s]);
                stk.push(mp(y, p));
            }
            else {
                stk.push(mp(y, p));
                dfs(y, p);
                lowpt[y.f][y.s] = min(lowpt[y.f][y.s], lowpt[p.f][p.s]);
            }
        }
    }
    comps.pb({});
    if(x != mp(-1, -1) && lowpt[y.f][y.s] >= num[x.f][x.s]) {
        while(stk.size() && stk.top() != mp(x, y)) {
            auto p = stk.top();
            auto p1 = p.f;
            auto p2 = p.s;
            pos[p1.f][p1.s] = (int)comps.size()-1;
            pos[p2.f][p2.s] = (int)comps.size()-1;
            comps[comps.size()-1].pb(p1);
            comps[comps.size()-1].pb(p2);
            stk.pop();
        }
        auto p = stk.top();
        auto p1 = p.f;
        auto p2 = p.s;
        pos[p1.f][p1.s] = (int)comps.size()-1;
        pos[p2.f][p2.s] = (int)comps.size()-1;
        comps[comps.size()-1].pb(p1);
        comps[comps.size()-1].pb(p2);
        stk.pop();
    }
}

vector<seti> tree;
vb reach;
int bc;

void dfs2(int x, int p, bool rc) {
    if(x == bc) rc = true;
    reach[x] = rc;
    for(auto e : tree[x]) {
        if(e != p) {
            dfs2(e, x, rc);
        }
    }
}

int main() {
    usaco();
    scd(n);
    scd(m);
    scd(q);
    pii bes, box;
    num = lowpt = grid = vvi(n, vi(m));
    frange(i, n) {
        string str;
        cin >> str;
        frange(j, m) {
            if(str[j] == '#') grid[i][j] = 1;
            if(str[j] == 'A') bes = mp(i, j);
            if(str[j] == 'B') box = mp(i, j);
        }
    }   
    pos = vvi(n, vi(m, -1));
    dfs(mp(-1, -1), bes);

    int sz = comps.size();
    printf("%d\n", sz);
    for(auto v : comps) {
        for(auto e : v) printf("%d %d; ", e.f, e.s);
        printf("\n");
    }
    tree = vector<seti>(sz);
    frange(i, sz) {
        for(auto p : comps[i]) {
            vii nex;
            nex.pb(mp(p.f+1, p.s));
            nex.pb(mp(p.f-1, p.s));
            nex.pb(mp(p.f, p.s+1));
            nex.pb(mp(p.f, p.s-1));
            for(auto e : nex) {
                if(e.f < 0 || e.f >= n || e.s < m || e.s >= m || grid[e.f][e.s] || pos[e.f][e.s] == -1) continue;
                tree[i].insert(pos[e.f][e.s]);
                tree[pos[e.f][e.s]].insert(i);
                // printf("%d %d\n", i, pos[e.f][e.s]);
            }
        }
    }

    bc = pos[box.f][box.s];
    reach = vb(sz);
    dfs2(pos[bes.f][bes.s], -1, false);

    frange(_, q) {
        int x, y;
        scd(x);
        scd(y);
        x--;
        y--;
        if(pos[x][y] != -1 && reach[pos[x][y]]) printf("YES\n");
        else printf("NO\n");
    }



}