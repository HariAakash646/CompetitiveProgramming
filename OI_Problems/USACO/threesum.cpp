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
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
    freopen("threesum.in", "r", stdin);
   freopen("threesum.out", "w", stdout);
}

int main() {
    usaco();
    int n, q;
    scd(n);
    scd(q);

    vi val(n);
    frange(i, n) {
        int a;
        scd(a);
        val[i] = a;
    }

    lli dp[5001][5001] = {0};

    vi frq(2e6+1);

    forr(i, 2, n) {
        
        frange(l, i) frq[val[l] + 1e6]++;
        for(int l=0; l+i<n; l++) {
            frq[val[l] + 1e6]--;
            int r = l + i;
            dp[l][r] = dp[l+1][r] + dp[l][r-1] - dp[l+1][r-1];
            int v =  val[l] + val[r];
            if(-v+1e6>=0 && -v+1e6<=2e6) {
                int x = frq[-v+1e6];
                dp[l][r] += x; 
            }
            frq[val[r] + 1e6]++;
        }

        for(int l=n-i; l<n; l++) frq[val[l] + 1e6]--;
    }
    frange(i, q) {
        int l, r;
        scd(l);
        scd(r);
        l--;
        r--;
        printf("%lld\n", dp[l][r]);
    }
    
}