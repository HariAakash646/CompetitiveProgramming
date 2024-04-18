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

int n, l;
vvi rmin;
vii vec;

bool check(int x)
{
    vi dp(n, 1);
    frange(i, n)
    {
        frange(j, i)
        {
            if (abs(vec[i].s - vec[j].s) >= x)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    return *max_element(all(dp)) >= l;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        scd(n);
        scd(l);
        vec = vii(n);
        map<int, vi> pos;
        frange(i, n)
        {
            scd(vec[i].f);
            vec[i].s = i;
            pos[vec[i].f].pb(i);
        }
        sort(all(vec), greater<>());
        int ma = 0;
        for (auto p : pos)
        {
            ma = max(ma, abs((*prev(p.s.end()) - *(p.s.begin()))));
        }

        if (l > n)
        {
            printf("%d\n", ma);
            continue;
        }
        else
        {
            int lo = 0;
            int hi = n;
            while (lo != hi)
            {
                int mid = (lo + hi + 1) / 2;
                if (check(mid))
                {
                    lo = mid;
                }
                else
                {
                    hi = mid - 1;
                }
            }
            printf("%d\n", max(ma, lo));
        }
    }
}