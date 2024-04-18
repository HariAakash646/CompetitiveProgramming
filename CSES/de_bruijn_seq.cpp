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
map<pii, bool> vis;
vb vnd;

string out = "";

void dfs(int x) {
    vnd[x] = true;
    while(graph[x].size()) {
        auto p = graph[x].back();
        graph[x].pop_back();
        if(vis[mp(min(x, p.f), max(x, p.f))] || vnd[p.f]) continue;
        vis[mp(min(x, p.f), max(x, p.f))] = true;
        dfs(p.f);
    }

    out += char('0' + (x & 1));
}

int main() {
    int n;
    scd(n);

    int m = (1<<n);
    graph = vector<vii>(m);
    int id = 0;
    frange(i, m) {
        int a = (((i<<1) | 1) & (m-1));
        // printf("%d %d ", i, a);
        if(a != i) graph[i].pb(mp(a, id++));
        a = ((i<<1) & (m-1));
        // printf("%d\n", a);
        if(a != i) graph[i].pb(mp(a, id++));
    }
    vnd = vb(m);
    dfs(0);
    // frange(i, n-1) out += '0';
    reverse(all(out));
    string out2 = "";
    frange(i, n-2) out2 += '0';
    for(auto e : out) out2 += e;
    if(n >= 2) out2 += '0';
    cout << out2;



}