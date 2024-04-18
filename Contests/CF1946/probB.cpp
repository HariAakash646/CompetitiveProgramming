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

const lli mod = 1e9 + 7;

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        lli k;
        sclld(k);
        vi vec(n+1);
        lli tot = 0;
        forr(i, 1, n+1) {
            scd(vec[i]); 
            tot += vec[i]+mod;
            tot %= mod;
        }

        vll dp(n+1);
        forr(i, 1, n+1) {
            dp[i] = max(0LL, vec[i] + dp[i-1]);
        }
        lli ma = *max_element(all(dp));
        ma %= mod;
        tot -= ma + mod;
        tot %= mod;
        frange(i, k) {
            ma *= 2;
            ma %= mod;
        }
        ma = (ma + tot+mod)%mod;
        printf("%lld\n", ma);
    }
}