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
    freopen("piepie.in", "r", stdin);
   freopen("piepie.out", "w", stdout);
}

int main() {
    usaco();
    int n, d;
    scd(n);
    scd(d);

    vector<vii> v(2, vii(n));

    vector<set<pii>> val(2);
    queue<pair<pii, int>> q;
    frange(i, n) {
        scd(v[0][i].f);
        scd(v[0][i].s);

        val[1].insert(mp(v[0][i].s, i));
        if(v[0][i].s == 0) {
            q.push(mp(mp(i, 0), 1));
        }
    }

    frange(i, n) {
        scd(v[1][i].s);
        scd(v[1][i].f);

        val[0].insert(mp(v[1][i].s, i));
        if(v[1][i].s == 0) q.push(mp(mp(i, 1), 1));
    }

    vvi dist(2, vi(n, -1));
    vector<vb> vis(2, vb(n));


    while(q.size()) {
        auto p = q.front();
        q.pop();
        if(vis[p.f.s][p.f.f]) continue;
        vis[p.f.s][p.f.f] = true;
        dist[p.f.s][p.f.f] = p.s;

        auto it = val[p.f.s].upper_bound(mp(v[p.f.s][p.f.f].f, 1e9+5));

        vector<pii> era;
        while(it != val[p.f.s].begin()) {
            it--;
            if((*it).f < v[p.f.s][p.f.f].f - d) break;
            era.pb(*it);
            q.push(mp(mp((*it).s, !p.f.s), p.s+1));
        }
        for(auto e : era) val[p.f.s].erase(e);
    }
    
    for(auto e : dist[0]) printf("%d\n", e);


}