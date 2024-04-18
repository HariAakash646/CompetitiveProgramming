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
   //  freopen("dishes.in", "r", stdin);
   // freopen("dishes.out", "w", stdout);
}

lli dist(lli x1, lli y1, lli x2, lli y2) {
    return (x1 - x2) * (x1- x2) + (y1 - y2) * (y1 - y2);
}

vi disset, sze;

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
}

int main() {
    // usaco();
    int n, k;
    scd(n);
    
    vector<vector<pair<lli, int>>> vec(11);
    vector<pair<lli, lli>> val(n);
    frange(i, n) {
        lli x;
        lli y;
        sclld(x);
        sclld(y);
        vec[y].pb(mp(x, i));
        val[i] = mp(x, y);
    }
    frange(i, 11) sort(all(vec[i]));

    vector<pair<lli, pii>> edges;

    frange(i, n) {
        auto p = val[i];
        frange(j, 11) {
            if(j != p.s) {
                auto it = lower_bound(all(vec[j]), mp(p.f, 0));
                if(it != vec[j].end()) {
                    lli d = dist(p.f, p.s, (*it).f, j);
                    edges.pb(mp(d, mp(i, (*it).s)));
                }
                if(it != vec[j].begin()) {
                    it--;
                    lli d = dist(p.f, p.s, (*it).f, j);
                    edges.pb(mp(d, mp(i, (*it).s)));
                }
            }
            else {
                auto it = lower_bound(all(vec[j]), mp(p.f+1, 0));
                if(it != vec[j].end()) {
                    lli d = dist(p.f, p.s, (*it).f, j);
                    edges.pb(mp(d, mp(i, (*it).s)));
                }
                it = lower_bound(all(vec[j]), mp(p.f, 0));
                if(it != vec[j].begin()) {
                    it--;
                    lli d = dist(p.f, p.s, (*it).f, j);
                    edges.pb(mp(d, mp(i, (*it).s)));
                }
            }
        }
    }
    sort(all(edges));

    disset = sze = vi(n+1);
    forr(i, 1, n+1) disset[i] = i;
    lli tot = 0;
    for(auto p : edges) {
        if(findf(p.s.f) != findf(p.s.s)) {
            unionf(p.s.f, p.s.s);
            tot += p.f;
        }
    }
    printf("%lld", tot);

}