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

vi fact(int x) {
    vi out;
    for(int i=1; i*i<=x; i++) {
        if(x % i == 0) {
            out.pb(i);
            if(x / i != i && i != 1) out.pb(x/i);
        }
    }
    sort(all(out));
    return out;
}

int main() {
    // usaco();
    int n;
    scd(n);

    vi vec(n+1);
    int ma = 0;
    forr(i, 1, n+1) {
        scd(vec[i]);
        ma = max(ma, vec[i]);
    }

    vi val(n+2, 1);
    val[0] = 0;
    val[n+1] = 0;
    vll contrib(n+2);
    contrib[1] = 1;
    vvi pos(ma+1);

    forr(i, 1, n+1) {
        // vi fac = fact(vec[i]);
        // for(auto e : fac) {
        //     pos[vec[i]/e - 1].pb(i);
        //     printf("%d %d\n", i, vec[i]/e-1);
        // }
        // printf("%d:\n", i);
        int v = 1;
        int pre = vec[i];
        for(int j=1; j*j<=vec[i]; j++) {
            pos[(vec[i]+j-1)/j-1].pb(i);
            int tm = (vec[i]+j-1)/j-1;
            if(tm == 0) continue;
            v = (vec[i]+tm-1)/tm;
            pre = tm;
        }
        while(v < vec[i]) {
            int lo = 1;
            int hi = pre-1;
            while(lo < hi) {
                int mid = (lo+hi+1)/2;
                if((vec[i]+mid-1)/mid > v) {
                    lo = mid;
                }
                else hi = mid-1;
            }
            v = (vec[i]+lo-1)/lo;
            pos[lo].pb(i);
            pre = lo;
            // printf("%d %d\n", v, lo);
        }
    }

    vll out(ma+1);
    out[ma] = 1;
    lli tot = 1;

    for(int i=ma-1; i>=1; i--) {
        for(auto e : pos[i]) {
            int v = (vec[e] + i - 1)/i;
            val[e] = v;
            lli d = max(0, val[e] - val[e-1]);
            tot -= contrib[e];
            tot += d;
            contrib[e] = d;
            d = max(0, val[e+1] - val[e]);
            tot -= contrib[e+1];
            tot += d;
            contrib[e+1] = d;
        }
        out[i] = tot;
    }

    forr(i, 1, ma+1) printf("%lld ", out[i]);



}