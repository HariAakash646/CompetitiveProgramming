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

int k, n, m, o;
vector<vii> graph, revg;
vvi lef, righ;
vi out;

void rec(int l, int r, vector<pair<pii, int>> quer) {
    if(l >= r) return;
    int mid = (l+r)/2;

    forr(i, l, mid+1) {
        frange(j, 2*k) lef[i][j] = 1e9 + 5;
    }
    forr(i, mid+1, r+1) {
        frange(j, 2*k) righ[i][j] = 1e9 + 5;
    }

    for(int i=mid; i>=l; i--) {
        frange(j, 2*k) {
            if(i == mid-j) lef[i][j] = 0;
            else {
                for(auto e : graph[i]) {
                    if(e.f <= mid) lef[i][j] = min(lef[i][j], lef[e.f][j] + e.s);
                }
            }
        }
    }

    forr(i, mid+1, r+1) {
        frange(j, 2*k) {
            if(i == mid+1+j) righ[i][j] = 0;
            else {
                for(auto e : revg[i]) {
                    if(e.f >= mid+1) righ[i][j] = min(righ[i][j], righ[e.f][j] + e.s);
                }
            }
        }
    }

    vector<pair<pii, int>> lv, rv;
    for(auto p1 : quer) {
        auto p = p1.f;
        if(p.f <= mid && p.s > mid) {
            int mi = 1e9;
            for(int i=max(l, mid-2*k+1); i<=mid; i++) {
                for(auto e : graph[i]) {
                    if(e.f > mid) {
                        mi = min(mi, lef[p.f][mid-i] + e.s + righ[p.s][e.f-(mid+1)]);
                    }
                }
            }
            if(mi == 1e9) mi = -1;
            out[p1.s] = mi;
        }
        else if(p.f <= mid) lv.pb(p1);
        else rv.pb(p1);
    }

    rec(l, mid, lv);
    rec(mid+1, r, rv);


}

int main() {
    // usaco();
    scd(k);
    scd(n);
    scd(m);
    scd(o);

    revg = graph = vector<vii>(n+1);

    frange(i, m) {
        int a, b, v;
        scd(a);
        scd(b);
        scd(v);
        a++;
        b++;
        graph[a].pb(mp(b, v));
        revg[b].pb(mp(a, v));
    }

    lef = righ = vvi(n+1, vi(2*k));
    vector<pair<pii, int>> query(o);

    frange(i, o) {
        scd(query[i].f.f);
        scd(query[i].f.s);
        query[i].f.f++;
        query[i].f.s++;
        query[i].s = i;
    }
    out = vi(o);
    rec(1, n, query);

    for(auto e : out) printf("%d\n", e);


}