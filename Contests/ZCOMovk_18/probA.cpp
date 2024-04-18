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

int main() {
    // usaco();
    int n;
    scd(n);

    vi vec(n);
    frange(i, n) scd(vec[i]);

    vi dp(n+1);
    int id = 0;
    int st = 0;
    dp[n] = n-1;
    forr(i, 1, n) {
        if(vec[i] == vec[i-1]) {
            forr(j, st, i) {
                dp[j] = i-1;
            }
            st = i;
        }
    }
    forr(i, st, n) dp[i] = n-1;

    int ma = 0;
    frange(i, n) {
        int id = dp[dp[dp[i]+1]+1];
        ma = max(ma, id - i + 1);
    }
    printf("%d", ma);
}