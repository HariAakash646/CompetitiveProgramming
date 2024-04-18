// Not working
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
    int n;
    scd(n);
    vi vec(n);
    frange(i, n)
    {
        scd(vec[i]);
    }
    vi dp;
    vi pos;
    frange(i, n)
    {
        int e = vec[i];
        int idx = lower_bound(all(dp), e) - dp.begin();
        if (idx == dp.size())
        {
            dp.pb(e);
            pos.pb(i + 1);
        }
        else
        {
            dp[idx] = e;
            pos[idx] = i + 1;
        }
    }
    int maxlen = 1;
    int currlen = 1;
    vi maxind = {pos[0]};
    vi currind = {pos[0]};
    forr(i, 1, dp.size())
    {
        if (dp[i] - dp[i - 1] == 1)
        {
            currlen++;
            currind.pb(pos[i]);
            if (currlen > maxlen)
            {
                maxind = currind;
                maxlen = currlen;
            }
        }
        else
        {
            currlen = 1;
            currind = {pos[i]};
        }
    }
    printf("%d\n", maxlen);
    for (int e : maxind)
    {
        printf("%d ", e);
    }
}