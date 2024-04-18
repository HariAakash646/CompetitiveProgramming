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
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
}

int main() {
    // usaco();
    int r, n;
    lli l, k;
    sclld(l);
    scd(r);
    scd(n);
    sclld(k);

    if(r == 2) {
        lli mi = 1e18;

        frange(i, n) {
            lli a;
            sclld(a);
            lli t = min(a, l-a);
            lli p;
            if(a >= l/2) p = a - l/2;
            else p = a + l/2;
            lli ti = p * k;
            if(ti < t) ti += lli(l)*k;
            mi = min(mi, ti);
        }
        printf("%lld", mi);
        return 0;
    }

    vll vec(n);

    frange(i, n) {
        sclld(vec[i]);
    }
    sort(all(vec));

    vector<vll> dp(n, vll(1<<r, 1e18));

    frange(i, n) {
        dp[i][1] = min(vec[i], l - vec[i]);
    }

    forr(i, 2, 1<<r) {
        frange(j, n) {
            frange(i1, r) {
                if(i & (1<<i1)) {
                    lli ti = dp[j][i^(1<<i1)];
                    ld p = (ld(ti) / ld(k));
                    p = p - lli(p/l) * l;
                    // lli lo = 0;
                    // lli hi = p/l;
                    // while(lo != hi) {
                    //     lli mid = (lo + hi)/2;
                    //     if(p - l * mid >= )
                    // }
                    // while(p - l >= l) p-=l;
                    lli rem = ti % k;
                    ld p1 = (p + ld(l/r) * ld(i1));
                    p1 = p1 - lli(p1/l) * l;

                    // cout << p << " " << p1 << "\n";
                    // while(p1 - l >= l) p1-=l;
                    lli v;
                    if(p1 <= ld(vec[j])) {
                        v = round((ld(vec[j]) - p1) * k);
                    } 
                    else v = round((ld(l) - p1 + ld(vec[j])) * k);
                    dp[j][i] = min(dp[j][i], dp[j][i^(1<<i1)] + v);
                }
            }
            frange(i1, j) {
                dp[j][i] = min(dp[j][i], dp[i1][i] + min(vec[j] - vec[i1], l - vec[j] + vec[i1]));
                dp[i1][i] = min(dp[i1][i], dp[j][i] + min(vec[j] - vec[i1], l - vec[j] + vec[i1]));
            }
        }
    }

    lli mi = 1e18;
    frange(i, n) {
        mi = min(mi, dp[i][(1<<r)-1]);
    }
    printf("%lld", mi);
}