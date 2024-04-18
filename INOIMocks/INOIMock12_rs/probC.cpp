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
//    freopen("problem.out", "w", stdout);
}

struct line {
    lli m, c;

    lli eval(lli x) {
        return m*x + c;
    }

    ld intersect(line y) {
        return ld(y.c - c) / ld(m - y.m);
    }
};

int main() {
    // usaco();
    int n;
    scd(n);
    vll hgt(n+1), co(n+1);

    forr(i, 1, n+1) sclld(hgt[i]);
    forr(i, 1, n+1) sclld(co[i]);

    vll pref(n+1);
    forr(i, 1, n+1) pref[i] = pref[i-1] + co[i];

    // vll dp(n+1, 1e18);
    // dp[1] = 0;

    // deque<line> dq;
    // dq.pb({-2*hgt[1], hgt[1]*hgt[1] - pref[1]});

    // forr(i, 2, n+1) {
    //     while(dq.size() >= 2 && dq[1].eval(hgt[i]) <= dq[0].eval(hgt[i])) dq.pop_front();
    //     dp[i] = dq.front().eval(hgt[i]) + pref[i-1] + hgt[i] * hgt[i];
    //     line l = {-2*hgt[i], dp[i] + hgt[i]*hgt[i] - pref[i]};
    //     while(dq.size() >= 2 && dq[dq.size()-2].intersect(l) <= dq.back().intersect(l)) dq.pop_back();
    //     dq.pb(l);
    // }


    // printf("%lld", dp[n]);

    vll h1(1e6+1, 1e18), h2(1e6+1, 1e18);
    set<lli> val;

    forr(i, 2, n) {
        for(int j=max(0LL, hgt[i]-4); j<=min(lli(1e6), hgt[i]+4); j++) {
            h2[hgt[i]] = min(h2[hgt[i]], h1[j] + (j - hgt[i]) * (j-hgt[i]) - co[i]);
        }
        auto it = val.upper_bound(hgt[i]);
        if(it != val.end()) {
            h2[hgt[i]] = min(h2[hgt[i]], h1[*it] + (*it - hgt[i]) * (*it-hgt[i]) - co[i]);
        }
        if(it != val.begin()) {
            it--;
            h2[hgt[i]] = min(h2[hgt[i]], h1[*it] + (*it - hgt[i]) * (*it-hgt[i]) - co[i]);
        }
        h1[hgt[i]] = min(h1[hgt[i]], (hgt[1] - hgt[i]) * (hgt[1] - hgt[i]) - co[i]);
        val.insert(hgt[i]);
    }
    lli tot = 0;
    forr(i, 2, n) tot += co[i];
    lli mi = tot + (hgt[1] - hgt[n]) * (hgt[1] - hgt[n]);

    forr(i, 0, 1e6+1) {
        mi = min(mi, h2[i] + (i - hgt[n]) * (i - hgt[n]) + tot);
        mi = min(mi, h1[i] + (i - hgt[n]) * (i-hgt[n]) + tot);
    } 
    printf("%lld", mi);
}