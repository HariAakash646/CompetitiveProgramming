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

int mex(vi &vec) {
    mpii mv;
    for(auto e : vec) mv[e]++;
    frange(e, (int)vec.size()+10) {
        if(mv.find(e) == mv.end()) return e;
    }
    return vec.size();

}

int main() {
    // usaco();
    int lim = 2000;
    vi dp(lim+1);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    forr(i, 3, lim+1) {
        vi vec;
        for(int j=1; 2*j<i; j++) {
            vec.pb(dp[j] ^ dp[i-j]);
        }
        dp[i] = mex(vec);
    }

    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        if(n >= 2000 || dp[n]) printf("first\n");
        else printf("second\n");
    }

}