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

int main()
{
    int n, c;
    scd(n);
    scd(c);
    vll val(c + 1);

    frange(i, n)
    {
        int c1;
        lli h, d;
        scd(c1);
        sclld(d);
        sclld(h);
        val[c1] = max(val[c1], d * h);
    }

    vll ma(c + 1);
    forr(i, 1, c + 1)
    {
        lli v = val[i];
        for (int j = i; j <= c; j += i)
        {
            ma[j] = max(ma[j], v);
            v += val[i];
        }
    }
    forr(i, 1, c + 1)
    {
        ma[i] = max(ma[i], ma[i - 1]);
    }
    int m;
    scd(m);

    frange(i, m)
    {
        lli d, h;
        sclld(d);
        sclld(h);
        lli v = d * h;
        auto it = upper_bound(all(ma), v);
        if (it == ma.end())
        {
            printf("-1 ");
        }
        else
        {
            printf("%d ", it - ma.begin());
        }
    }
}