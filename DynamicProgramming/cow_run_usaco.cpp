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
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

int main()
{
    freopen("cowrun.in", "r", stdin);
    freopen("cowrun.out", "w", stdout);
    int n;
    scd(n);
    vi vec(n);
    frange(i, n) scd(vec[i]);
    sort(all(vec));

    vvi dp1(n, vi(n, 1e9));
    vvi dp2(n, vi(n, 1e9));

    frange(i, n)
    {
        dp1[i][i] = abs(vec[i]) * n;
        dp2[i][i] = abs(vec[i]) * n;
    }

    forr(k, 1, n)
    {
        for (int i = 0; i + k < n; i++)
        {
            dp1[i][i + k] = min(dp1[i][i + k - 1] + abs(vec[i + k] - vec[i + k - 1]) * (n - k), dp2[i][i + k - 1] + abs(vec[i + k] - vec[i]) * (n - k));
            dp2[i][i + k] = min(dp1[i + 1][i + k] + abs(vec[i] - vec[i + k]) * (n - k), dp2[i + 1][i + k] + abs(vec[i] - vec[i + 1]) * (n - k));
        }
    }
    printf("%d", min(dp1[0][n - 1], dp2[0][n - 1]));
}