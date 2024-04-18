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

int n, k;
vector<vll> dp;
vvi opt;
vll vec, pref;

void dnc(int i, int l, int r, int optl, int optr) {
    if(l > r) return;
    int mid = (l+r)/2;
    forr(k, optl, min(optr+1, mid)) {
        if(dp[i-1][k] + (pref[mid] - pref[k]) * (pref[n] - pref[mid]) > dp[i][mid]) {
            dp[i][mid] = dp[i-1][k] + (pref[mid] - pref[k]) * (pref[n] - pref[mid]);
            opt[i][mid] = k;
        }
    }
    dnc(i, l, mid-1, optl, optr);
    dnc(i, mid+1, r, optl, optr);

}

int main() {
    // usaco();
    
    scd(n);
    scd(k);
    dp = vector<vll>(k+1, vll(n+1, -1e17));
    opt = vvi(k+1, vi(n+1));
    vec = pref = vll(n+1);
    forr(i, 1, n+1) {
        sclld(vec[i]);
        pref[i] = pref[i-1]+vec[i];
    }

    dp[0][0] = 0;
    forr(i, 1, k+1)
        dnc(i, 1, n, 0, n);

    lli ma = -1e9;
    int id = -1;

    forr(i, 1, n+1) {
        if(dp[k][i] > ma) {
            ma = dp[k][i];
            id = i;
        }
    }

    vi out;

    for(int i=k; i>=1; i--) {
        out.pb(id);
        id = opt[i][id];
    }
    printf("%lld\n", ma);
    reverse(all(out));
    for(auto e : out) printf("%d ", e);



}