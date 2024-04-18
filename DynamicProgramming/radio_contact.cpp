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

lli dist(pii p1, pii p2)
{
    return (p1.f - p2.f) * (p1.f - p2.f) + (p1.s - p2.s) * (p1.s - p2.s);
}

int main()
{
    freopen("radio.in", "r", stdin);
    freopen("radio.out", "w", stdout);
    int n, m;
    scd(n);
    scd(m);
    int fx, fy;
    scd(fx);
    scd(fy);
    int bx, by;
    scd(bx);
    scd(by);
    string fpath, bpath;
    cin >> fpath;
    cin >> bpath;
    vii fpos(n + 1);
    vii bpos(m + 1);
    fpos[0] = {fx, fy};
    bpos[0] = {bx, by};
    frange(i, n)
    {
        fpos[i + 1] = fpos[i];
        if (fpath[i] == 'N')
        {
            fpos[i + 1].s++;
        }
        else if (fpath[i] == 'S')
        {
            fpos[i + 1].s--;
        }
        else if (fpath[i] == 'E')
        {
            fpos[i + 1].f++;
        }
        else if (fpath[i] == 'W')
        {
            fpos[i + 1].f--;
        }
    }
    frange(i, m)
    {
        bpos[i + 1] = bpos[i];
        if (bpath[i] == 'N')
        {
            bpos[i + 1].s++;
        }
        else if (bpath[i] == 'S')
        {
            bpos[i + 1].s--;
        }
        else if (bpath[i] == 'E')
        {
            bpos[i + 1].f++;
        }
        else if (bpath[i] == 'W')
        {
            bpos[i + 1].f--;
        }
    }
    vector<vll> dp(n + 1, vll(m + 1));
    dp[0][0] = 0;
    forr(i, 1, n + 1)
    {
        dp[i][0] = dp[i - 1][0] + dist(fpos[i], bpos[0]);
    }
    forr(i, 1, m + 1)
    {
        dp[0][i] = dp[0][i - 1] + dist(fpos[0], bpos[i]);
    }
    forr(i, 1, n + 1)
    {
        forr(j, 1, m + 1)
        {
            dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + dist(fpos[i], bpos[j]);
        }
    }
    printf("%lld", dp[n][m]);
}