#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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

vll dp;
vll pref, tot;

void dnc(int l, int r, int st, int en)
{
    int mid = (l + r) / 2;
    int optim = min(st, mid);

    forr(i, max(st, mid - 1), en + 1)
    {
        lli v = tot[i] - tot[mid - 1] - ((pref[i] - pref[mid - 1]) * (mid - 1));
        if (v >= dp[mid])
        {
            dp[mid] = v;
            optim = i;
        }
    }

    if (mid - 1 >= l)
        dnc(l, mid - 1, st, optim);
    if (mid + 1 <= r)
        dnc(mid + 1, r, optim, en);
}

int main()
{
    int n;
    scd(n);

    dp = vll(n + 1);

    vll vec(n + 1);

    frange(i, n)
    {
        sclld(vec[i + 1]);
    }
    pref = tot = vll(n + 1);
    forr(i, 1, n + 1)
    {
        pref[i] = pref[i - 1] + vec[i];
        tot[i] = tot[i - 1] + vec[i] * i;
    }
    dnc(1, n, 1, n);
    lli ma = 0;
    forr(i, 1, n + 1) ma = max(ma, dp[i]);
    printf("%lld", ma);
}