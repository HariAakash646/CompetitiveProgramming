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

const lli mod = 1e9+7;

int main() {
    // usaco();
    int t;
    scd(t);

    vll dp1(1e5+1), dp2(1e5+1);

    dp1[0] = 1;

    forr(i, 1, 1e5+1) {
        dp1[i] = dp2[i-1];
        dp2[i] = dp1[i-1];

        forr(j, 2, 5) {
            if(i - j >= 0) {
                dp1[i] += dp1[i-j];
                dp2[i] += dp2[i-j];
            }
        } 
        dp1[i] %= mod;
        dp2[i] %= mod;
    }
    

    frange(_, t) {
        int n;
        scd(n);

        lli tot = 0;
        forr(j, 1, 5) {
            if(n - j >= 0) {
                tot += dp1[n-j];
            }
        } 
        tot %= mod;
        printf("%lld\n", tot);
    }
}