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

int dist(pii a, pii b)
{
    return (a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s);
}

int main()
{
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);
    int h, g;
    scd(h);
    scd(g);
    vii posh(h + 1);
    vii posg(g + 1);
    frange(i, h)
    {
        scd(posh[i + 1].f);
        scd(posh[i + 1].s);
    }
    frange(i, g)
    {
        scd(posg[i + 1].f);
        scd(posg[i + 1].s);
    }
    vvi dp1(h + 1, vi(g + 1));
    vvi dp2(h + 1, vi(g + 1));
    // vector<vii> pre(h+1, vi(g+1));
    forr(i, 2, h + 1)
    {
        dp1[i][0] = dp1[i - 1][0] + dist(posh[i], posh[i - 1]);
        dp2[i][0] = 1e9;
    }

    forr(j, 1, g + 1)
    {
        dp2[0][j] = 1e9; // dp2[0][j - 1] + pow(posg[j].f - posg[j - 1].f, 2) + pow(posg[j].s - posg[j - 1].s, 2);
        dp1[0][j] = 1e9;
    }
    forr(i, 1, h + 1)
    {
        forr(j, 1, g + 1)
        {
            dp1[i][j] = min(dp1[i - 1][j] + dist(posh[i], posh[i - 1]), dp2[i - 1][j] + dist(posh[i], posg[j]));
            dp2[i][j] = min(dp1[i][j - 1] + dist(posg[j], posh[i]), dp2[i][j - 1] + dist(posg[j], posg[j - 1]));
        }
    }
    // forr(i, 0, h + 1)
    // {
    //     forr(j, 0, g + 1)
    //     {
    //         printf("%d ", dp1[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // forr(i, 0, h + 1)
    // {
    //     forr(j, 0, g + 1)
    //     {
    //         printf("%d ", dp2[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d", dp1[h][g]);
}