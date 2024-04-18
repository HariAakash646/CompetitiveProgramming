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
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
    freopen("cave.in", "r", stdin);
   freopen("cave.out", "w", stdout);
}

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const lli mod = 1e9 + 7;

vector<vector<pair<pii, lli>>> disset;

pii findf(pii x) {
    if(x == disset[x.f][x.s].f) return x;
    disset[x.f][x.s].f = findf(disset[x.f][x.s].f);
    return disset[x.f][x.s].f;
}

void unionf(pii x, pii y) {
    x = findf(x);
    y = findf(y);
    if(x == y) return;
    disset[y.f][y.s].f = x;
    disset[x.f][x.s].s *= disset[y.f][y.s].s;
    disset[x.f][x.s].s %= mod;
}

int main() {
    usaco();
    fastio();
    int n, m;
    cin >> n >> m;

    vector<vii> grid(n);
    vvi pos(n, vi(m));

    frange(i, n) {
        string row;
        cin >> row;
        pii curr = mp(-1, -1);
        frange(j, m) {
            if(row[j] == '.') {
                if(curr.f != -1) curr.s++;
                else curr = mp(j, j);
            }
            else {
                if(curr.f != -1) grid[i].pb(curr);
                curr = mp(-1, -1);
                pos[i][j] = -1;
            }
        }
    }
    disset = vector<vector<pair<pii, lli>>>(n, vector<pair<pii, lli>>(m));
    frange(i, n) {
        frange(j, m) {
            if(pos[i][j] != -1) disset[i][j] = mp(mp(i, j), 1);
        }
    }
    
    frange(j, m) {
        if(pos[n-1][j]!=-1) {
            if(j > 0 && pos[n-1][j-1] != -1) unionf(mp(n-1, j), mp(n-1, j-1));
        }
    }

    set<pii> st;
    frange(j, m) {
        if(pos[n-1][j] != -1) {
            st.insert(findf(mp(n-1, j)));
        }
    }
    for(auto p : st) {
        disset[p.f][p.s].s++;
        disset[p.f][p.s].s %= mod;
    }

    lli out = 1;
        
    for(int i=n-2; i>=0; i--) {
        frange(j, m) {
            if(pos[i][j]!=-1) {
                if(j > 0 && pos[i][j-1] != -1) unionf(mp(i, j), mp(i, j-1));
                if(pos[i+1][j] != -1) unionf(mp(i, j), mp(i+1, j));
            }
        
        }

        set<pii> st;
        frange(j, m) {
            if(pos[i][j] != -1) {
                st.insert(findf(mp(i, j)));
            }
        }
        for(auto p : st) {
            disset[p.f][p.s].s++;
            disset[p.f][p.s].s %= mod;
        }
    }
    st = {};
    frange(i, n) {
        frange(j, m) {
            if(pos[i][j] != -1) st.insert(findf(mp(i, j)));
        }
    }

    for(auto p : st) {
        out *= disset[p.f][p.s].s;
        out %= mod;
    }
    cout << out;
}