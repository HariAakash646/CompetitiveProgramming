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

vi disset, sze;

int findf(int x) {
    if(x == disset[x]) return x;
    disset[x] = findf(disset[x]);
    return disset[x];
}

bool unionf(int x, int y) {
    x = findf(x);
    y = findf(y);
    if(x == y) return false;
    disset[y] = x;
    return true;
}

vector<vii> graph;
vi val;
vi out;

void dfs(int x, int p) {
    out[x] = !out[p];
    for(auto e : graph[x]) {
        if(e.f != p) {
            val[e.f] = e.s;
            dfs(e.f, x);
            val[x] = min(val[x], e.s);
        }
    }
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    vector<pair<int, pii>> edg(m);

    frange(i, m) {
        
        scd(edg[i].s.f);
        scd(edg[i].s.s);
        scd(edg[i].f);
    }

    sort(all(edg));

    disset = vi(n+1);
    forr(i, 1, n+1) disset[i] = i;

    int ma = 0;

    graph = vector<vii>(n+1);

    for(auto p : edg) {
        if(unionf(p.s.f, p.s.s)) {
            ma = max(ma, p.f);
            graph[p.s.f].pb(mp(p.s.s, p.f));
            graph[p.s.s].pb(mp(p.s.f, p.f));
        }
    }

    out = vi(n+1);
    val = vi(n+1, 1e9+5);
    dfs(1, 0);

    printf("%d\n", *max_element(next(val.begin()), val.end()));
    forr(i, 1, n+1) {
        if(out[i]) printf("B");
        else printf("D");
    }


}