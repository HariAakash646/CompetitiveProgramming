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

int n;

vll pref, vec;

lli sum(int l, int r) {
    if(l > r) return 0;
    return pref[r] - pref[l-1];
}

bool check(lli x) {
    vll dp(n+1);
    deque<int> dq;
    dq.pb(0);

    forr(i, 1, n+1) {
        while(dq.size() && sum(dq.front()+1, i-1) > x) dq.pop_front();
        if(dq.size())
            dp[i] = dp[dq.front()] + vec[i];
        else dp[i] = x + 1e9;
        while(dq.size() && dp[i] < dp[dq.back()]) dq.pop_back();
        dq.pb(i);
    }

    lli tot = 0;
    for(int i=n; i>=0; i--) {
        if(tot > x) return false;
        if(dp[i] <= x) return true;
        tot += vec[i];
    }
    return false;
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        
        scd(n);
        pref = vec = vll(n+1);

        forr(i, 1, n+1) {
            sclld(vec[i]);
            pref[i] = pref[i-1] + vec[i];
        }

        lli lo = 1;
        lli hi = 1e15;

        while(lo != hi) {
            lli mid = (lo+hi)/2;
            if(check(mid)) hi = mid;
            else lo = mid+1;
        }
        printf("%lld\n", lo);
    }
}