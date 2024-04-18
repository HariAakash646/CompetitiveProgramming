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
    int n;
    scd(n);
    vi vec(n);
    lli tot = 0;
    frange(i, n)
    {
        scd(vec[i]);
        tot += vec[i];
    }
    int v1 = tot / n;
    int v2 = (tot + n - 1) / n;

    // cout << v1 << "\n";
    lli o1 = 0;
    lli o2 = 0;
    for (auto e : vec)
    {
        if (e >= v1)
            o1 += e - (v1 + 1);
        else
            o2 += v1 - e;
    }

    lli x1 = max(o1, o2);

    // cout << v2 << "\n";
    o1 = 0;
    o2 = 0;
    for (auto e : vec)
    {
        if (e >= v2)
            o1 += e - (v2 + 1);
        else
            o2 += v2 - e;
    }
    lli x2 = max(o1, o2);
    printf("%lld", min(x1, x2));
}