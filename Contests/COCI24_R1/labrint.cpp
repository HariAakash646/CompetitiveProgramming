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

vector<vector<vector<pair<pii, int>>>> graph;

vector<vb> vis;

void dfs(int x, int y, int v) {
    if(vis[x][y]) return;
    vis[x][y] = true;
    for(auto p : graph[x][y]) {
        if(v & (1<<p.s)) {
            dfs(p.f.f, p.f.s, v);
        }
    }
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    graph = vector<vector<vector<pair<pii, int>>>>(n+1, vector<vector<pair<pii, int>>>(m+1));
    map<char, int> mv;
    mv['P'] = 0;
    mv['C'] = 1;
    mv['Z'] = 2;
    mv['N'] = 3;
    forr(i, 1, n+1) {
        string str;
        cin >> str;
        forr(j, 1, m) {
            graph[i][j].pb(mp(mp(i, j+1), mv[str[j-1]]));
            graph[i][j+1].pb(mp(mp(i, j), mv[str[j-1]]));
        }
    }

    forr(i, 1, n) {
        string str;
        cin >> str;
        forr(j, 1, m+1) {
            graph[i][j].pb(mp(mp(i+1, j), mv[str[j-1]]));
            graph[i+1][j].pb(mp(mp(i, j), mv[str[j-1]]));
        }
    }

    int q;
    scd(q);

    frange(_, q) {
        int a, b, c, d;
        scd(a);
        scd(b);
        scd(c);
        scd(d);
        int mi = 4;

        frange(i, 16) {
            vis =  vector<vb>(n+1, vb(m+1));
            dfs(a, b, i);
            if(vis[c][d]) mi = min(mi, __builtin_popcount(i));
        }
        printf("%d\n", mi);
    }

    


}