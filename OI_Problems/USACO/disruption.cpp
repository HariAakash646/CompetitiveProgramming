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
    freopen("disrupt.in", "r", stdin);
    freopen("disrupt.out", "w", stdout);
}

vector<vii> graph;
vector<vii> gr2;

vi out;

void dfs(int x, int p, set<pii> &st) {
    for(auto e : gr2[x]) {
        if(st.find(e) == st.end()) st.insert(e);
        else st.erase(e);
    }
    for(auto e : graph[x]) {
        if(e.f != p) {
            set<pii> st2;
            dfs(e.f, x, st2);
            if(st2.size()) {
                out[e.s] = (*st2.begin()).f;
            }
            else out[e.s] = -1;
            if(st2.size() > st.size()) swap(st, st2);
            for(auto e : st2) {
                if(st.find(e) == st.end()) st.insert(e);
                else st.erase(e);
            }
        }

    }
}

int main() {
    usaco();
    int n, m;
    scd(n);
    scd(m);

    graph = vector<vii>(n+1);
    gr2 = vector<vii>(n+1);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(mp(b, i));
        graph[b].pb(mp(a, i));
    }

    frange(i, m) {
        int a, b, c;
        scd(a);
        scd(b);
        scd(c);
        gr2[a].pb(mp(c, i));
        gr2[b].pb(mp(c, i));
    }

    out = vi(n-1);
    set<pii> st;
    dfs(1, 0, st);
    for(auto e : out) printf("%d\n", e);
}