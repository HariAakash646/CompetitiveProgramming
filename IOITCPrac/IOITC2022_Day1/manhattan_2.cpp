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

vi val[2][2];

bool cmp(pair<pii, int> x, pair<pii, int> y) {
    return x.f.s < y.f.s;
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, k;
        scd(n);
        scd(k);
        
        vector<pair<pii, int>> vec(n);

        frange(i, n) {
            scd(vec[i].f.f);
            scd(vec[i].f.s);
            vec[i].s = i+1;
        }
        sort(all(vec));
        lli tot = 0;
        frange(i, 2) frange(j, 2) val[i][j] = {};
        vb xpos(n+1);
        frange(i, n/2) {
            tot -= vec[i].f.f;
        }
        forr(i, n/2, n) {
            tot += vec[i].f.f;
            xpos[vec[i].s] = true;
        }

        sort(all(vec), cmp);

        frange(i, n/2) {
            tot -= vec[i].f.s;
            val[xpos[vec[i].s]][0].pb(vec[i].s);
        }

        forr(i, n/2, n) {
            tot += vec[i].f.s;
            val[xpos[vec[i].s]][1].pb(vec[i].s);
        }
        printf("%lld\n", tot);
        frange(i, val[0][0].size()) {
            printf("%d %d\n", val[0][0][i], val[1][1][i]);
        }
        frange(i, val[0][1].size()) {
            printf("%d %d\n", val[0][1][i], val[1][0][i]);
        }

    }
}