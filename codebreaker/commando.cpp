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

struct line {
    lli m, c;

    lli eval(lli x) {
        return m * x + c;
    }

    ld intersect(line y) {
        return ld(y.c - c) / ld(m - y.m);
    }
};

int main() {
    // usaco();
    int n;
    scd(n);
    lli a, b, c;
    sclld(a);
    sclld(b);
    sclld(c);

    vll vec(n+1);

    forr(i, 1, n+1) sclld(vec[i]);

    vll pref(n+1);

    forr(i, 1, n+1) {
        pref[i] = pref[i-1] + vec[i];
    }

    vll dp(n+1, -1e18);
    dp[0] = 0;

    deque<line> dq;
    line tmp = {b, 0};
    dq.pb(tmp);

    forr(i, 1, n+1) {
        lli v = pref[i];
        while(dq.size() >= 2 && dq[1].eval(v) >= dq[0].eval(v)) dq.pop_front();
        dp[i] = dq.front().eval(v) + a * pref[i] * pref[i] + c;
        line l = {-2*a*pref[i] + b, a * pref[i] * pref[i] + dp[i] - b * pref[i]};

        while(dq.size() >= 2 && dq[dq.size()-2].intersect(l) <= dq[dq.size()-2].intersect(dq.back())) dq.pop_back();
        dq.pb(l);
    }

    printf("%lld", dp[n]);
}