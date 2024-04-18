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

vvi lift;

int binlift(int a, int b)
{
    if (a == b)
        return 0;
    int ans = 0;
    for (int i = 20; i >= 0; i--)
    {
        if (lift[i][a] != b)
        {
            a = lift[i][b];
            ans += (1 << i);
        }
    }
    if (lift[0][a] == b)
        return ans + 1;
    else
        return -1;
}

int main()
{
    int n, q;
    scd(n);
    scd(q);

    lift = vvi(21, vi(n + 1));

    frange(i, n)
    {
        int p;
        scd(p);
        lift[0][i] = p;
    }

    forr(i, 1, 21)
    {
        forr(j, 1, n + 1)
        {
            lift[i][j] = lift[i - 1][lift[i - 1][j]];
        }
    }

    frange(i, q)
    {
        int a, b;
        scd(a);
        scd(b);
        printf("%d\n", binlift(a, b));
    }
}