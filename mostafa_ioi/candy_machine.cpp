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

    vector<pair<pii, pii>> vec(n);

    frange(i, n) {
        int x, y;
        scd(x);
        scd(y);
        vec[i].f = mp(y-x, (x+y));
        vec[i].s = mp(x, y);
    }
    sort(all(vec));

    vi lis(n+1, 2e9+5);
    vector<vii> out(n+1);
    lis[0] = -(2e9+5);

    for(auto p1 : vec) {

        pii p = p1.f;
        p.s = -p.s;
        // printf("%d %d\n", p.f, p.s);
        int id = lower_bound(all(lis), p.s) - lis.begin();
        lis[id] = p.s;
        out[id].pb(p1.s);
    }

    int c = 0;
    frange(i, n+1) {
        if(lis[i] != 2e9+5) c = i;
    }

    printf("%d\n", c);
    forr(i, 1, c+1) {
        for(auto p : out[i]) printf("%d %d %d\n", p.f, p.s, i);
    }

}