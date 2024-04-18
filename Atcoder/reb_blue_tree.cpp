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
vb vis;
vi col;
vi comp;
map<pii, int> mv;
vi out;

vi disset, sze, sze2;
int findf(int x)
{
    while (x != disset[x])
    {
        x = disset[x];
    }
    return x;
}

void unionf(int x, int y)
{
    x = findf(x);
    y = findf(y);
    if (x == y)
        return;
    if (sze[x] < sze[y])
    {
        swap(x, y);
    }
    disset[y] = x;
    sze[x] = max(sze[x], sze[y] + 1);
    sze2[x] += sze2[y];
}


void dfs(int x) {
    comp.pb(x);
    vis[x] = true;
    for(auto e : graph[x]) {
        if(col[e.f] == col[x] && col[x] == e.s && !vis[e.f]) {
            out.pb(mv[mp(min(e.f, x), max(e.f, x))]);
            unionf(e.f, x);
            dfs(e.f);
        }
    }
}

int main() {
    usaco();
    int n, m;
    scd(n);
    scd(m);
    graph = vector<vii>(n+1);

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        char c;
        cin >> c;
        graph[a].pb(mp(b, (c=='R')));
        graph[b].pb(mp(a, (c=='R')));
        mv[mp(min(a, b), max(a, b))] = i+1;
    }
    string str;
    cin >> str;

    col = vi(n+1);

    frange(i, n) col[i+1] = (str[i] == 'R');

    disset = vi(n+1);
    sze2 = sze = vi(n+1, 1);

    forr(i, 1, n+1) disset[i] = i;

    vvi comps;
    int id = 0;
    vi pos(n+1);
    vis = vb(n+1);
    forr(i, 1, n+1) {
        if(!vis[i]) {
            comp = {};
            dfs(i);
            comps.pb(comp);
            for(auto e : comp) pos[e] = id;
            id++;
        }
    }

    for(auto v : comps) {
        if(v.size() == 1) {
            int x = v[0];
            bool done = false;
            for(auto e : graph[x]) {
                // printf("%d %d %d %d\n", e.f, x, findf(e.f), findf(x));
                if(e.s == col[x] && findf(e.f) != findf(x)) {
                    done = true;
                    out.pb(mv[{min(x, e.f), max(x, e.f)}]);
                    unionf(e.f, x);
                    break;
                }
            }
            if(!done) {
                printf("No");
                return 0;
            }
        }
    }

    for(auto v : comps) {
        if(v.size() > 1) {
            for(auto x : v) {
                for(auto e : graph[x]) {
                    if(findf(e.f) != findf(x)) {
                        out.pb(mv[{min(x, e.f), max(x, e.f)}]);
                        unionf(e.f, x);
                    }
                }
            }
        }
    }

    printf("Yes\n");
    for(auto e : out) printf("%d ", e);

}