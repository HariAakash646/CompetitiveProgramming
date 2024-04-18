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
    int t;
    scd(t);
    frange(_, t)
    {
        int m, k, a1, ak;
        scd(m);
        scd(k);
        scd(a1);
        scd(ak);
        int v = m - a1;
        int val = (v + k - 1) / k * k;
        int c = 1e9;
        if (val <= m)
        {
            c = max(0, val / k - ak);
        }
        int c2 = max(0, m / k - ak);
        m = m % k;
        c2 += max(0, m - a1);
        printf("%d\n", min(c, c2));
    }
}