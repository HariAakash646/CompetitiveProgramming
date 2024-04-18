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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    // freopen("pcb.in", "r", stdin);
    // freopen("pcb.out", "w", stdout);

    int n;
    scd(n);
    vi vec(1e6 + 10, -1);
    int l, r;
    frange(i, n)
    {
        scd(l);
        scd(r);
        vec[r] = l;
    }
    reverse(all(vec));
    vi dp;
    for (int i : vec)
    {
        if (i == -1)
            continue;
        int idx = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
        if (idx == dp.size())
        {
            dp.pb(i);
        }
        else
        {
            dp[idx] = i;
        }
    }
    cout << dp.size();
}