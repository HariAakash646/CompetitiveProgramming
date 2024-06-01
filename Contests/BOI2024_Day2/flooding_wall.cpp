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

const lli mod = 1e9 + 7;

int main() {
    // usaco();
    int n;
    scd(n);
    vii vec(n+1);
    forr(i, 1, n+1) scd(vec[i].f);
    forr(i, 1, n+1) scd(vec[i].s);

    seti st;
    for(auto p : vec) {
        st.insert(p.f);
        st.insert(p.s);
    }

    mpii mv;
    int id = 0;
    for(auto e : st) mv[e] = id++;

    frange(i, n+1) {
        vec[i].f = mv[vec[i].f];
        vec[i].s = mv[vec[i].s];
    } 
    int m = st.size();
    vi val(m+1);
    for(auto p : mv) {
        val[p.s] = p.f;
    }
    vector<vi> dp1(2, vi(m+1)), dp2(2, vi(m+1)), suf1(2, vi(m+1)), suf2(2, vi(m+1));
    vvi val1(n+2, vi(4)), val2(n+2, vi(4));
    dp1[0][0] = 1;
    dp2[1][0] = 1;

    forr(i, 1, n+1) {
        forr(j, 0, vec[i].f+1) {
            dp1[1][vec[i].f] += dp1[0][j];
            dp1[1][vec[i].f] %= mod;
        }
        forr(j, vec[i].f+1, m+1) {
            dp1[1][j] += dp1[0][j];
            dp1[1][j] %= mod;
        }
        forr(j, 0, vec[i].s+1) {
            dp1[1][vec[i].s] += dp1[0][j];
            dp1[1][vec[i].s] %= mod;
        }
        forr(j, vec[i].s+1, m+1) {
            dp1[1][j] += dp1[0][j];
            dp1[1][j] %= mod;
        }
        suf1[1][m] = vi(m+1);
        suf1[1][m] = dp1[1][m];
        for(int j=m-1; j>=0; j--) {
            suf1[1][j] = (dp1[1][j] + suf1[1][j+1]) % mod;
        }
        val1[i][0] = suf1[1][vec[i].f];
        if(vec[i].f < m)
            val1[i][2] = suf1[1][vec[i].f+1];
        val2[i][0] = suf1[1][vec[i].s];
        if(vec[i].s < m)
            val2[i][2] = suf1[1][vec[i].s+1];
        dp1[0] = dp1[1];
        dp1[1] = vi(m+1);
    }

    for(int i=n; i>=1; i--) {
        forr(j, 0, vec[i].f+1) {
            dp2[0][vec[i].f] += dp2[1][j];
            dp2[0][vec[i].f] %= mod;
        }
        forr(j, vec[i].f+1, m+1) {
            dp2[0][j] += dp2[1][j];
            dp2[0][j] %= mod;
        }
        forr(j, 0, vec[i].s+1) {
            dp2[0][vec[i].s] += dp2[1][j];
            dp2[0][vec[i].s] %= mod;
        }
        forr(j, vec[i].s+1, m+1) {
            dp2[0][j] += dp2[1][j];
            dp2[0][j] %= mod;
        }
        suf2[0] = vi(m+1);
        suf2[0][m] = dp2[0][m];
        for(int j=m-1; j>=0; j--) {
            suf2[0][j] = (dp2[0][j] + suf2[0][j+1]) % mod;
        }
        val1[i][1] = suf2[0][vec[i].f];
        if(vec[i].f < m)
            val1[i][3] = suf2[0][vec[i].f+1];
        val2[i][1] = suf2[0][vec[i].s];
        if(vec[i].s < m)
            val2[i][3] = suf2[0][vec[i].s+1];
        dp2[1] = dp2[0];
        dp2[0] = vi(m+1);
    }

    lli tot = 0;

    forr(i, 2, n) {
        forr(j, vec[i].f+1, m) {
            tot += (dp1[i-1][j] * (lli)suf2[i+1][j] % mod) * (val[j]-val[vec[i].f]) % mod;
            tot %= mod;
            if(j<m)
                tot += (suf1[i-1][j+1] * (lli)dp2[i+1][j] % mod) * (val[j]-val[vec[i].f]) % mod;
            tot %= mod;
        }
        forr(j, vec[i].s+1, m) {
            tot += (dp1[i-1][j] * (lli)suf2[i+1][j] % mod) * (val[j]-val[vec[i].s]) % mod;
            tot %= mod;
            if(j<m)
                tot += (suf1[i-1][j+1] * (lli)dp2[i+1][j] % mod) * (val[j]-val[vec[i].s]) % mod;
            tot %= mod;
        }
    }
    printf("%lld", tot);
}