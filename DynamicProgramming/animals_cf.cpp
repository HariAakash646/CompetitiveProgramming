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
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, x;
    scd(n);
    scd(x);
    vi vec(n + 1);
    int a;
    forr(i, 1, n + 1)
    {
        scd(a);
        vec[i] = a * (n - i + 1);
    }
    vvi dp(x + 1, vi(n + 1));
    forr(i, 1, x + 1)
    {
        forr(j, 1, n + 1)
        {
            int v1, v2;
            v1 = 0;
            if (i - vec[j] >= 0)
            {
                v1 = dp[i - vec[j]][j - 1] + 1;
            }
            v2 = dp[i][j - 1];
            dp[i][j] = max(v1, v2);
        }
    }
    printf("%d", dp[x][n]);
}