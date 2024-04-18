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

int r, c;

struct Node {
    pii par;
    int l, r, u, d;
    int c;
};

vector<vector<Node>> disset;
vector<vb> vis;
vvi sze;

pii findf(pii x) {
    if(x != disset[x.f][x.s].par) {
        disset[x.f][x.s].par = findf(disset[x.f][x.s].par);
    }
    return disset[x.f][x.s].par;
}

void unionf(pii u, pii v) {
    if(v.f >= r || v.s >= c || v.f < 0 || v.s < 0) return;
    if(!vis[v.f][v.s]) return;

    auto ut = findf(u);
    auto vt = findf(v);

    if(ut == vt) return;

    if(sze[vt.f][vt.s] < sze[ut.f][ut.s]) swap(vt, ut);

    disset[vt.f][vt.s].par = ut;
    sze[ut.f][ut.s] = max(sze[vt.f][vt.s]+1, sze[ut.f][ut.s]);
    disset[ut.f][ut.s].c += disset[vt.f][vt.s].c;
    disset[ut.f][ut.s].l = min(disset[ut.f][ut.s].l, disset[vt.f][vt.s].l);
    disset[ut.f][ut.s].d = min(disset[ut.f][ut.s].d, disset[vt.f][vt.s].d);
    disset[ut.f][ut.s].r = max(disset[ut.f][ut.s].r, disset[vt.f][vt.s].r);
    disset[ut.f][ut.s].u = max(disset[ut.f][ut.s].u, disset[vt.f][vt.s].u);
}

int main() {
    // usaco();
    scd(r);
    scd(c);

    disset = vector<vector<Node>>(r, vector<Node>(c));
    sze = vvi(r, vi(c));

    vector<vii> pos(1e6+1);

    frange(i, r) {
        frange(j, c) {
            int v;
            scd(v);
            pos[v].pb(mp(i, j));
            disset[i][j].par = mp(i, j);
            disset[i][j].l = j;
            disset[i][j].r = j;
            disset[i][j].u = i;
            disset[i][j].d = i;
            disset[i][j].c = 1;
        }
    }
    int cnt = 0;
    vis = vector<vb>(r, vb(c));
    forr(i, 0, 1e6+1) {
        for(auto p : pos[i]) {
            vis[p.f][p.s] = true;
            unionf(p, mp(p.f+1, p.s));
            unionf(p, mp(p.f-1, p.s));
            unionf(p, mp(p.f, p.s+1));
            unionf(p, mp(p.f, p.s-1));
        }

        set<pii> st;
        for(auto p : pos[i]) st.insert(findf(p));
        for(auto e : st) {
            auto p = disset[e.f][e.s];
            if(p.r == c-1 || p.u == r-1 || p.l == 0 || p.d == 0) continue;
            int l = p.r - p.l + 1;
            int b = p.u - p.d + 1;
            if(l * b == p.c) {cnt++;}
        }
    }

    printf("%d", cnt);




}