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
typedef vector<lli> vll;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

const lli mod = 1e9 + 7;

lli binexp(lli v, lli c) {
    if(c == 0) return 1;
    lli out = binexp(v, c/2);
    out = out * out;
    out %= mod;
    if(c % 2) out = (out * v) % mod;
    return out % mod;
}

int main() {
    // usaco();
    int n, q, c;
    scd(n);
    scd(q);
    scd(c);

    vii vec(q);
    frange(i, q) {
        scd(vec[i].f);
        scd(vec[i].s);
    }

    sort(all(vec));

    int pre = 0;

    vii out;

    for(auto p : vec) {
        if(p.s != pre) {
            out.pb(p);
            pre = p.s;
        }
    }
    vec = out;
    q = vec.size();

    vector<vll> dp(q, vll(c+1));
    lli val = 0;
    forr(i, 2, c+1) {
        lli tot = (binexp(i-1, vec[0].f) - binexp(i-2, vec[0].f) + mod) % mod;

        tot *= binexp(i-1, vec[0].s - vec[0].f-1);
        tot %= mod;
        val += tot;
        val %= mod;
        dp[0][i] = (val + dp[0][i-1]) % mod;
        // printf("%lld\n", dp[0][i]-dp[0][i-1]);
    }

    forr(j, 1, q) {
        lli val = 0;
        forr(i, 2, c+1) {
            lli tot = (binexp(i-1, vec[j].f - vec[j-1].s) - binexp(i-2, vec[j].f - vec[j-1].s) + mod) % mod;
            tot *= binexp(i-1, vec[j].s - vec[j].f-1);
            tot %= mod;
            tot *= dp[j-1][i-2];
            tot %= mod;
            tot += ((dp[j-1][i-1] - dp[j-1][i-2] + mod) % mod) * binexp(i-1, vec[j].s - vec[j-1].s - 1);
            tot %= mod;
            val += tot;
            val %= mod;
            dp[j][i] = (val + dp[j][i-1]) % mod;
        }
    }

    lli tot = 0;

    // frange(i, c+1) {
    //     tot += dp[q-1][i];
    //     tot %= mod;
    // }

    printf("%lld", dp[q-1][c]*binexp(c, n-vec[q-1].s) % mod);


}