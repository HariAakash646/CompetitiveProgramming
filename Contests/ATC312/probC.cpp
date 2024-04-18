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

vi v1, v2;

bool check(int x)
{
    // int c1 = upper_bound(all(v1), x) - v1.begin();
    // int c2 = v2.end() - lower_bound(all(v2), x);
    int c1 = 0, c2 = 0;
    for (auto e : v1)
    {
        if (e <= x)
            c1++;
    }
    for (auto e : v2)
    {
        if (e >= x)
            c2++;
    }
    return c1 >= c2;
}

int main()
{
    int n, m;
    scd(n);
    scd(m);
    v1 = vi(n);
    v2 = vi(m);

    frange(i, n) scd(v1[i]);
    frange(i, m) scd(v2[i]);
    sort(all(v1));
    sort(all(v2));
    int lo = 0;
    int hi = 1e9 + 10;
    while (lo != hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            hi = mid;
        }
        else
            lo = mid + 1;
    }
    printf("%d", lo);
}