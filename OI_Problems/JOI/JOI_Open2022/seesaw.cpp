// Not working
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

struct coord
{
    ld l;
    ld r;
    ld curr;
};

coord minc(coord x, coord y)
{
    if (x.r - x.l < y.r - y.l)
    {
        return x;
    }
    else
    {
        return y;
    }
}

int main()
{
    int n;
    scd(n);
    vi vec(n + 1);
    forr(i, 1, n + 1)
    {
        scd(vec[i]);
    }
    vector<vector<coord>> dp(n + 1, vector<coord>(n + 1));
    forr(i, 0, n)
    {
        for (int j = 1; j + i <= n; j++)
        {
            if (i == 0)
            {
                dp[j][j].l = vec[j];
                dp[j][j].r = vec[j];
                dp[j][j].curr = vec[j];
                continue;
            }
            ld pos = (dp[j][i + j - 1].curr * i + vec[j + i]) / ld(i + 1);
            coord c1, c2;
            c1.l = min(pos, dp[j + 1][j + i].l);
            c1.r = max(pos, dp[j + 1][j + i].r);
            c2.l = min(pos, dp[j][j + i - 1].l);
            c2.r = max(pos, dp[j][j + i - 1].r);
            c1.curr = pos;
            c2.curr = pos;
            dp[j][j + i] = minc(c1, c2);
        }
    }
    forr(i, 1, n + 1)
    {
        forr(j, 1, n + 1)
        {
            cout << i << " " << j << " " << dp[i][j].r << " " << dp[i][j].l << "\n";
        }
        cout << "\n";
    }
    // cout << dp[1][n].r - dp[1][n].l;
}