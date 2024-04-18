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
    int n, k;
    scd(n);
    scd(k);
    vector<vb> dp1(100 * n + 1, vb(n + 1)), dp2(100 * n + 1, vb(n + 1));
    vi a(n + 1), b(n + 1);

    forr(i, 1, n + 1) scd(a[i]);
    forr(i, 1, n + 1) scd(b[i]);

    dp1[0][0] = dp2[0][0] = true;
    forr(i, 1, 100 * n + 1)
    {
        forr(j, 1, n + 1)
        {
            dp1[i][j] = dp1[i][j - 1];
            if (i - a[j] >= 0)
                dp1[i][j] = dp1[i][j] || dp1[i - a[j]][j - 1];
        }
    }

    forr(i, 1, 100 * n + 1)
    {
        forr(j, 1, n + 1)
        {
            dp2[i][j] = dp2[i][j - 1];
            if (i - b[j] >= 0)
                dp2[i][j] = dp2[i][j] || dp2[i - b[j]][j - 1];
        }
    }
    int v = -1;
    forr(i, 1, 100 * n + 1)
    {
        if (dp1[i][n] && i % k == 0 && dp2[i / k][n])
        {
            v = i;
        }
    }
    printf("%d", v);
}