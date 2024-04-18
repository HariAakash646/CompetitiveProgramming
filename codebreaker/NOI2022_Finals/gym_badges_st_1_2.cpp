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
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

int main()
{
    int n;
    scd(n);
    vector<pair<lli, lli>> vec(n);
    frange(i, n) sclld(vec[i].f);
    frange(i, n) sclld(vec[i].s);

    if (n <= 10)
    {
        int ma = 0;
        vector<vector<pair<bool, lli>>> dp(1 << n, vector<pair<bool, lli>>(n, {false, 0}));
        frange(i, n) dp[0][i] = {true, 0};
        forr(i, 1, 1 << n)
        {
            frange(j, n)
            {
                bool done = false;
                if (i & (1 << j))
                {
                    frange(k, n)
                    {
                        if (k != j && dp[i ^ (1 << j)][k].f && dp[i ^ (1 << j)][k].s <= vec[j].s)
                        {
                            done = true;
                        }
                    }
                }
                if (done)
                {
                    lli v = 0;
                    frange(k, n)
                    {
                        if (i & (1 << k))
                        {
                            v += vec[k].f;
                        }
                    }
                    dp[i][j].f = true;
                    dp[i][j].s = v;
                    ma = max(ma, __builtin_popcount(i));
                }
            }
        }
        printf("%d", ma);
    }
    else
    {
        sort(all(vec));
        int c = 0;
        lli v = 0;
        for (auto p : vec)
        {
            if (v > p.s)
                break;
            v += p.f;
            c++;
        }
        printf("%d", c);
    }
}