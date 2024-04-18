#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

int mod = 15746;
int main()
{
    int n;
    scd(n);
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    forr(i, 2, n + 1, 1)
    {
        dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
    }
    printf("%d", dp[n]);

    return 0;
}