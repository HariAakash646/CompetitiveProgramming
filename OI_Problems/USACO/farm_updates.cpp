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

vi disset;
vi on;
vector<vi> val;
vi out;

int findf(int x) {
    if(x == disset[x]) return x;
    disset[x] = findf(disset[x]);
    return disset[x];
}

void unionf(int u, int v, int id) {
    u = findf(u);
    v = findf(v);
    if(on[v]) swap(u, v);
    if(u == v) return;
    if(!on[v] && on[u]) {
        for(auto e : val[v]) {
            out[e] = id;
        }
    }
    if(!on[v] && !on[u]) {
        if(val[v].size() > val[u].size()) {
            swap(val[u], val[v]);
        }
        for(auto e : val[v]) val[u].pb(e);
    }
    disset[v] = u;
}

int main() {
    // usaco();
    fastio();
    int n, q;
    cin >> n >> q;

    vector<pair<pii, int>> edg;
    vi act(n+1, 1);
    vii quer;

    forr(i, 1, q+1) {
        char c;
        cin >> c;
        if(c == 'A') {
            int a, b;
            cin >> a >> b;
            edg.pb(mp(mp(a, b), 1));
        }
        else if(c == 'D') {
            int a;
            cin >> a;
            act[a] = 0;
            quer.pb(mp(-i, a));
        }
        else {
            int a;
            cin >> a;
            edg[a-1].s = 0;
            quer.pb(mp(i, a-1));
        }
    }

    out = vi(n+1);
    disset = vi(n+1);
    on = vi(n+1);
    val = vvi(n+1);

    forr(i, 1, n+1) {
        disset[i] = i;
        on[i] = act[i];
        val[i].pb(i);
        if(act[i]) out[i] = q;
    }

    for(auto p : edg) {
        if(p.s) {
            unionf(p.f.f, p.f.s, q);
        }
    }

    reverse(all(quer));

    for(auto p : quer) {
        if(p.f < 0) {
            int x = findf(p.s);
            if(on[x]) continue;
            else {
                on[x] = true;
                for(auto e : val[x]) out[e] = -p.f - 1;
                val[x] = {};
            }
        }
        else {
            unionf(edg[p.s].f.f, edg[p.s].f.s, p.f-1);
        }
    }

    forr(i, 1, n+1) cout << out[i] << "\n";

}