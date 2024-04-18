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
    cin >> n;
    vector<vi> cnt(n, vi(26));
    
    frange(i, n) {
        string str;
        cin >> str;
        for(auto e : str) {
            cnt[i][int(e-'a')]++;
        }
    }

    vector<pair<int, vi>> com(1<<n, mp(0, vi(26, 1e6)));

    frange(i, 1<<n) {
        frange(j, n) {
            if(i & (1<<j)) {
                vi tmp = com[i^(1<<j)].s;
                int tot = 0;
                frange(k, 26) {
                    tmp[k] = min(tmp[k], cnt[j][k]);
                    tot += tmp[k];
                }
                com[i] = mp(tot, tmp);
            }
        }
    }

    vector<lli> dp(1<<n, 1e18);

    frange(i, n) {
        dp[1<<i] = com[1<<i].f;
    }

    forr(i, 1, 1<<n) {
        for(int j=(i-1)&i; j>0; j=(j-1)&i) {
            dp[i] = min(dp[i], dp[j] + dp[i^j] - com[i].f);
        }
    }

    printf("%lld", dp[(1<<n)-1]+1);
}