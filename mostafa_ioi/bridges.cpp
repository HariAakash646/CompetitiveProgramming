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

vi disset, sze, cnt, out;
stack<pii> stk;
int n, m;

int findf(int x) {
    while(x != disset[x]) {
        x = disset[x];
    }
    return x;
}

void unionf(int u, int v) {
    u = findf(u);
    v = findf(v);
    if(u == v) return;
    if(sze[u] > sze[v]) swap(u, v);
    disset[u] = v;
    sze[v] = max(sze[v], sze[u]+1);
    stk.push(mp(u, v));
    cnt[v] += cnt[u];
}

vector<pair<int, pii>> edge;

void process(vector<pair<pii, pii>> quer) {
    vb change(m);
    stk = {};
    vector<pair<pii, int>> calc;
    vector<pair<pii, int>> upd;
    vvi uped(m);
    disset = vi(n+1);
    forr(i, 1, n+1) disset[i] = i;
    sze = cnt= vi(n+1, 1);
    for(auto p : quer) {

        if(p.f.s == 1) {
            // printf("%d\n", p.s.s);
            change[p.s.s] = true;
            upd.pb(mp(p.s, p.f.f));
            uped[p.s.s].pb(p.f.f);
        }
        else calc.pb(mp(p.s, p.f.f));
    }
    // upd.pb(mp(mp(0, 0), 1e6));
    sort(all(calc), greater<>());

    vector<pair<int, pii>> st;
    frange(i, m) {
        auto p = edge[i];
        if(!change[i])
            st.pb(p);
    }
    sort(all(st));
    // printf("upd:\n");
    // for(auto p1 : upd) {
        
    //     printf("%d %d\n", edge[p1.f.s].s.f, edge[p1.f.s].s.s);
    // }
    // printf("std:\n");
    // for(auto p1 : st) {
        
    //     printf("%d %d\n", p1.s.f, p1.s.s);
    // }
    int it = st.size();
    vi idx(m);
    for(auto p : calc) {
        // printf("%d:\n", p.s);
        stk = {};
        frange(i, upd.size()) {
            auto p1 = upd[i];
            int v = edge[p1.f.s].f;
            auto it = idx[p1.f.s];
            idx[p1.f.s]++;
            if(p1.s < p.s) v = p1.f.f;
            else if(it > 0) continue;
            if(it+1 != uped[p1.f.s].size() && uped[p1.f.s][it+1] < p.s) continue;
            if(v >= p.f.f) {
                unionf(edge[p1.f.s].s.f, edge[p1.f.s].s.s);
                // printf("upd %d %d\n", edge[p1.f.s].s.f, edge[p1.f.s].s.s);
            }
        }
        frange(i, upd.size()) {
            auto p1 = upd[i];
            idx[p1.f.s] = 0;
        }
        auto it1 = it;
        while(it != 0 && st[it-1].f >= p.f.f) {
            it--;
            auto p1 = st[it];
            unionf(p1.s.f, p1.s.s);
            // printf("std %d %d\n", p1.s.f, p1.s.s);
            
        }
        out[p.s] = cnt[findf(p.f.s)];
        while(stk.size()) {
            auto p1 = stk.top();
            stk.pop();
            disset[p1.f] = p1.f;
            cnt[p1.s] -= cnt[p1.f];
        }

        
        it = it1;
        while(it != 0 && st[it-1].f >= p.f.f) {
            it--;
            auto p1 = st[it];
            unionf(p1.s.f, p1.s.s);
        }
    }

    for(auto p : upd) {
        edge[p.f.s].f = p.f.f;
    }

}

int main() {
    // usaco();
    scd(n);
    scd(m);
    edge = vector<pair<int, pii>>(m);

    frange(i, m) {
        scd(edge[i].s.f);
        scd(edge[i].s.s);
        scd(edge[i].f);
    }

    int q;
    scd(q);

    int sq = sqrt(q);

    vector<pair<pii, pii>> quer;
    out = vi(q, -1);
    frange(i, q) {
        pair<pii, pii> p;
        p.f.f = i;
        scd(p.f.s);
        scd(p.s.s);
        scd(p.s.f);
        if(p.f.s == 1) p.s.s--;
        quer.pb(p);
        if(quer.size() >= sq) {
            process(quer);
            quer = {};
        }
    }
    process(quer);

    for(auto e : out) if(e != -1) {printf("%d\n", e);}


}