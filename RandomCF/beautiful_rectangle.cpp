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

int main() {
    // usaco();
    int n;
    scd(n);

    vi vec(n);
    map<int, int> mv;
    frange(i, n) {
        scd(vec[i]);
        mv[vec[i]]++;
    }

    vi cnt;
    
    for(auto p : mv) {
        cnt.pb(p.s);
    }
    sort(all(cnt));
    vi pref = cnt;
    forr(i, 1, pref.size()) {
        pref[i] += pref[i-1];
    }
    int x = cnt.size();
    pair<int, pii> ma = mp(0, mp(0, 0));
    forr(i, 1, x+1) {
        int id = upper_bound(all(cnt), i) - cnt.begin();
        int tot = 0;
        if(id) tot += pref[id-1];
        tot += (x-id) * i;
        int b = tot / i;
        if(b>=i)
        ma = max(ma, mp(i*b, mp(i, b)));
    }
    vi v2;
    vii mv2;
    for(auto p : mv) mv2.pb(mp(p.s, p.f));
    sort(all(mv2), greater<>());
    for(auto p : mv2) {
        frange(i, min(p.f, ma.s.f)) {
            v2.pb(p.s);
        }
    }
    int id = 0;
    printf("%d\n", ma.f);
    int a = ma.s.f;
    int b = ma.s.s;
    vvi grid(a, vi(b));
    x=0;
    int y=0;
    frange(i, ma.f) {
        while(grid[x][y]) {
            x = (x+1)%a;
        }
        grid[x][y] = v2[id];
        id++;
        x=(x+1)%a;
        y = (y+1)%b;
    }

    printf("%d %d\n", a, b);
    for(auto v : grid) {
        for(auto e : v) {
            printf("%d ", e);
        }
        printf("\n");
    }
}