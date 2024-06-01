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

vi disset, sze;

int findf(int x) {
    if(x == disset[x]) return x;
    disset[x] = findf(disset[x]);
    return disset[x];
}

void unionf(int x, int y) {
    x = findf(x);
    y = findf(y);
    if(x == y) return;
    if(sze[x] > sze[y]) swap(x, y);
    disset[x] = y;
    sze[y] = max(sze[y], sze[x]+1);
}

vector<pair<int, pii>> vec;

lli dist(pii p1, pii p2) {
    return lli(p1.f - p2.f) * lli(p1.f - p2.f) + lli(p1.s - p2.s) * lli(p1.s - p2.s);
}

lli sq(lli v) {
    lli lo = 0;
    lli hi = 1e9;
    while(lo != hi) {
        lli mid = (lo+hi)/2;
        if(mid*mid>v) {
            hi = mid;
        }
        else {
            lo = mid+1;
        }
    }
    return lo;
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);
    int w, h;
    scd(w);
    scd(h);

    vector<pair<pii, int>> tree;

    frange(i, n) {
        int x, y, r;
        scd(x);
        scd(y);
        scd(r);
        frange(j, tree.size()) {
            auto p = tree[j];
            lli v = dist(mp(x, y), p.f);
            lli sv = sq(v) - r - p.s;
            vec.pb(mp((int)sv, mp(i, j)));
        }
        tree.pb(mp(mp(x, y), r));
    } 

    int x=0, y=0, r=0;
    frange(j, tree.size()) {
        auto p = tree[j];
        x = p.f.f;
        lli v = dist(mp(x, y), p.f);
        lli sv = sq(v) - r - p.s;
        vec.pb(mp((int)sv, mp(n, j)));
    }

    x=w, y=0;
    frange(j, tree.size()) {
        auto p = tree[j];
        y = p.f.s;
        lli v = dist(mp(x, y), p.f);
        lli sv = sq(v) - r - p.s;
        vec.pb(mp((int)sv, mp(n+1, j)));
    }

    x=w, y=h;
    frange(j, tree.size()) {
        auto p = tree[j];
        x = p.f.f;
        lli v = dist(mp(x, y), p.f);
        lli sv = sq(v) - r - p.s;
        vec.pb(mp((int)sv, mp(n+2, j)));
    }

    x=0, y=h;
    frange(j, tree.size()) {
        auto p = tree[j];
        y = p.f.s;
        lli v = dist(mp(x, y), p.f);
        lli sv = sq(v) - r - p.s;
        vec.pb(mp((int)sv, mp(n+3, j)));
    }

    disset = sze = vi(n+4, 1);
    frange(i, n+4) disset[i] = i;

    sort(all(vec));
    // for(auto p : vec) {
    //     printf("%d %d %d\n", p.f, p.s.f, p.s.s);
    // }
    vector<vb> out(m, vb(4, true));

    vector<pair<int, pii>> quer(m);

    frange(i, m) {
        scd(quer[i].f);
        quer[i].f *= 2;
        scd(quer[i].s.f);
        quer[i].s.s = i;
    }

    sort(all(quer));

    int id = 0;
    for(auto p : quer) {
        while(id < vec.size() && vec[id].f <= p.f) {
            unionf(vec[id].s.f, vec[id].s.s);
            // printf("%d %d\n", vec[id].s.f, vec[id].s.s);
            id++;
        }
        
        vi edg={0, 1, 2, 3};
        p.s.f--;
        frange(i, edg.size()) {
            edg[i] = (edg[i] + (p.s.f) + 4) % 4;
        }

        int oi = p.s.s;
        // printf("%d %d %d\n", p.s.s, n+edg[0], n+edg[3]);
        if(findf(n+edg[0]) == findf(n+edg[3])) {
            frange(i, 4) {
                if(i != p.s.f) out[oi][i] = false;
            }
        }

        if(findf(n+edg[0]) == findf(n+edg[2])) {
            out[oi][(p.s.f+1)%4] = false;
            out[oi][(p.s.f+2)%4] = false;
        }

        if(findf(n+edg[1]) == findf(n+edg[3])) {
            out[oi][(p.s.f+2)%4] = out[oi][(p.s.f+3)%4] = false;
        }

        forr(i, 1, 4) {
            if(findf(n+edg[i-1]) == findf(n+edg[i])) {
                out[oi][(p.s.f+i)%4] = false;
            }
        }
        
    }

    frange(i, m) {
        frange(j, 4) {
            if(out[i][j]) printf("%d", j+1);
        }
        printf("\n");
    }

}