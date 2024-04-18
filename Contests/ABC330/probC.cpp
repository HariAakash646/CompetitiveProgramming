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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    lli d;
    sclld(d);

    lli mi = d;

    vll sqr;

    for(lli i=0; i*i<=4e12; i++) {
        sqr.pb(i*i);
    }

    for(lli x=0; x<=2e6; x++) {
        lli v = d - x * x;
        auto it = lower_bound(all(sqr), v);
        if(it != sqr.end()) {
            // if(x < 10)
            // printf("%lld\n", *it);
            mi = min(mi, abs(*it + x * x - d));
        }
        if(it != sqr.begin()) {
            it--;
            // if(x < 10)
            // printf("%lld\n", *it);
            mi = min(mi, abs(*it + x * x - d));
        }
    }

    printf("%lld", mi);
}