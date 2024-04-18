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
    int n, m;
    scd(n);
    scd(m);

    string st1, st2;
    cin >> st1 >> st2;

    vector<vb> dp(n, vb(m));
    dp[0][0] = true;

    if(st1[0] != st2[0]) {
        printf("No");
        return 0;
    }

    forr(i, 1, n) {
        forr(j, 1, m) {
            if(st1[i] == st2[j]) dp[i][j] = dp[i-1][j-1] || dp[i-1][m-1];
        }
        
        if(st1[i] == st2[0]) {
            frange(j, m) {
                dp[i][0] = dp[i][0] || dp[i-1][j];
            }
        }
    }

    if(dp[n-1][m-1]) printf("Yes");
    else printf("No");
}