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
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

struct activ
{
    int swim = 0, bug = 0, hw = 0;
};

int main()
{
    int n;
    scd(n);
    vector<activ> vec(n + 1);
    forr(i, 1, n + 1)
    {
        scd(vec[i].swim);
        scd(vec[i].bug);
        scd(vec[i].hw);
    }
    vector<activ> dp(n + 1);
    forr(i, 1, n + 1)
    {
        dp[i].swim = max(dp[i - 1].bug, dp[i - 1].hw) + vec[i].swim;
        dp[i].bug = max(dp[i - 1].swim, dp[i - 1].hw) + vec[i].bug;
        dp[i].hw = max(dp[i - 1].bug, dp[i - 1].swim) + vec[i].hw;
    }
    printf("%d", max({dp[n].swim, dp[n].bug, dp[n].hw}));
}