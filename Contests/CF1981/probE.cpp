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

void unionf(int u, int v) {
    u = findf(u);
    v = findf(v);
    if(u==v) return;

    if(sze[v] > sze[u]) swap(u, v);
    disset[v] = u;
    sze[u] = max(sze[u], sze[v]+1);

}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);

        vector<pair<pii, int>> vec(n);
        frange(i, n) {
            scd(vec[i].f.f);
            scd(vec[i].f.s);
            scd(vec[i].s);
        }
        sort(all(vec));

        set<pii> st;
        set<pii> act;
        vector<pair<int, pii>> edg;
        frange(i, n) {
            auto p = vec[i];
            int l = p.f.f;
            while(act.size() && (*act.begin()).f < l) {
                auto p1 = *act.begin();
                st.erase(mp(vec[p1.s].s, p1.s));
                act.erase(act.begin());
            }
            st.insert(mp(p.s, i));
            act.insert(mp(p.f.s, i));
            auto it = st.find(mp(p.s, i));
            if(it != prev(st.end())) {
                auto p1 = *next(it);
                edg.pb(mp(p1.f-p.s, mp(i, p1.s)));
            }
            if(it != st.begin()) {
                auto p1 = *prev(it);
                edg.pb(mp(p.s-p1.f, mp(i, p1.s)));
            }
        }
        sort(all(edg));
        int c = 0;
        disset = sze = vi(n+1);
        forr(i, 1, n+1) disset[i] = i;
        lli tot = 0;
        for(auto p : edg) {
            if(findf(p.s.f) != findf(p.s.s)) {
                c++;
                tot += p.f;
                unionf(p.s.f, p.s.s);
            }
        }
        if(c==n-1) {
            printf("%lld\n", tot);
        }
        else {
            printf("-1\n");
        }
    }
}