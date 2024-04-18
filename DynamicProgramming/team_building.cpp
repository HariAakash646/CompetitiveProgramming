// Not working. Small bugs.
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
    int n, p, k;
    scd(n);
    scd(p);
    scd(k);
    vi avec(n);
    frange(i, n)
    {
        scd(avec[i]);
    }
    vector<pair<int, vi>> pos(n);
    frange(i, n)
    {
        frange(j, p)
        {
            pos[i].f = avec[i];
            int a;
            scd(a);
            pos[i].s.pb(a);
        }
    }
    sort(all(pos), greater<>());
    vvi dp(n + 1, vi(1 << p));
    forr(i, 1, n + 1)
    {
        frange(j, 1 << p)
        {
            int c = 0;
            frange(l, p)
            {
                if (j & (1 << l))
                {
                    c++;
                }
            }
            c = i - 1 - c;
            if (c < k)
            {
                dp[i][j] = dp[i - 1][j] + pos[i - 1].f;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
            frange(l, p)
            {
                if (j & (1 << l))
                    dp[i][j] = max(dp[i - 1][j ^ (1 << l)] + pos[i - 1].s[l], dp[i][j]);
            }
        }
    }

    printf("%d", dp[n][(1 << p) - 1]);
}