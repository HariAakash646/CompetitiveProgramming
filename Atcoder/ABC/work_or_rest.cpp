#include <bits/stdc++.h>

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
typedef vector<vll> vvll;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef pair<int, pii> piii;

lli inf = 1e18;

int main()
{
    int n;
    scd(n);
    vll vec(n + 1);
    frange(i, n)
    {
        sclld(vec[i + 1]);
    }
    vvll dp1(n + 1, vll(n + 2, 0));
    vvll dp2(n + 1, vll(n + 2, 0));
    forr(i, 2, n + 1)
    {
        forr(j, 0, n + 1)
        {
            if (j == 0)
            {
                dp1[i][j] = max(dp1[i - 1][1], dp2[i - 1][1]);
                dp2[i][j] = max(dp1[i - 1][1], dp2[i - 1][1]);
                continue;
            }
            dp1[i][j] = dp1[i - 1][j - 1] + vec[j];
            dp2[i][j] = max({dp1[i - 1][j - 1] + vec[j], dp1[i - 1][j] + vec[j], dp1[i - 1][j + 1] + vec[j], dp2[i - 1][j + 1] + vec[j]});
        }
    }
    lli ma = 0;
    frange(j, n + 1)
    {
        if (j > 0 && j < n)
            ma = max(dp1[n][j] + vec[j + 1], dp2[n][j] + vec[j - 1]);
        else if (j > 0)
            ma = dp2[n][j] + vec[j - 1];
        else
            ma = dp1[n][j] + vec[j + 1];
    }
    printf("%lld", ma);
}