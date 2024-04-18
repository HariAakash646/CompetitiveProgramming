#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;

void usaco() {
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

vector<vii> disset;
vvi sze;

int h, w, q;

pii findf(pii p) {
    if(p == disset[p.f][p.s]) return p;
    disset[p.f][p.s] = findf(disset[p.f][p.s]);
    return disset[p.f][p.s];
}

void unionf(pii p1, pii p2) {
    if(p2.f < 0 || p2.f >= h || p2.s < 0 || p2.s >= w) return;
    if(sze[p2.f][p2.s] == 0) return;
    p1 = findf(p1);
    p2 = findf(p2);

    if(p1 == p2) return;

    disset[p2.f][p2.s] = p1;
    sze[p1.f][p1.s] += sze[p2.f][p2.s]; 
}

void oper(pii p) {
    unionf(p, mp(p.f, p.s+1));
    unionf(p, mp(p.f, p.s-1));
    unionf(p, mp(p.f+1, p.s));
    unionf(p, mp(p.f-1, p.s));
}

int main() {
    // usaco();
    scd(h);
    scd(w);
    scd(q);

    vector<pair<int, pii>> vec;

    frange(i, h) {
        frange(j, w) {
            int a;
            scd(a);
            vec.pb(mp(a, mp(i, j)));
        }
    }

    sort(all(vec));

    vector<pair<pii, pii>> quer(q);
    frange(i, q) {
        scd(quer[i].s.f);
        scd(quer[i].s.s);
        scd(quer[i].f.f);
        quer[i].f.s = i;
    }

    disset = vector<vii>(h, vii(w));
    sze = vvi(h, vi(w));
    frange(i, h) {
        frange(j, w) {
            disset[i][j] = mp(i, j);
        }
    }
    vi out(q);
    sort(all(quer));
    int id = 0;
    for(auto p : quer) {
        while(id < vec.size() && vec[id].f < p.f.f) {
            sze[vec[id].s.f][vec[id].s.s] = 1;
            oper(vec[id].s);
            id++;
        }
        pii v = findf(mp(p.s.f-1, p.s.s-1));
        out[p.f.s] = sze[v.f][v.s];
    }

    for(auto e : out) printf("%d\n", e);



}