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
    lli n, m;
    sclld(n);
    sclld(m);
    lli i, j;
    sclld(i);
    sclld(j);
    if (i <= j)
    {
        lli v = m * (i - 1) + (n - (i - 1)) * (i - 1);
        if (i % 2 == 1)
        {
            printf("%lld", v + (j - (i - 1)));
        }
        else
            printf("%lld", v + 1 + m - j);
    }
    else if (j < i)
    {
        lli v = (j - 1) * n + (m - (j - 1)) * j;
        if (j % 2 == 1)
        {
            printf("%lld", v + (i - j));
        }
        else
        {
            printf("%lld", v + (n - i) + 1);
        }
    }
    // else {

    // }
}