#include <bits/stdc++.h>

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
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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

struct Person
{
    vll pos;
    lli aud = 1e18;

    bool operator>(const Person &y) const
    {
        return aud > y.aud;
    }
};

int main()
{
    int n, p, k;
    scd(n);
    scd(p);
    scd(k);

    Person e;
    e.pos = vll(p);

    vector<Person> vec(n + 1, e);
    forr(i, 1, n + 1) { sclld(vec[i].aud); }

    forr(i, 1, n + 1)
    {
        frange(j, p)
        {
            sclld(vec[i].pos[j]);
        }
    }

    sort(all(vec), greater<>());

    vector<vll> dp(n + 1, vll(1 << p, -1e17));
    dp[0][0] = 0;

    forr(i, 1, n + 1)
    {
        frange(j, 1 << p)
        {

            frange(l, p)
            {
                if (j & (1 << l))
                    dp[i][j] = max(dp[i][j], dp[i - 1][j ^ (1 << l)] + vec[i].pos[l]);
            }
            if (i - __builtin_popcount(j) <= k)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + vec[i].aud);
            }
            else
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
    }
    // for (auto v : dp)
    // {
    //     for (auto e : v)
    //     {
    //         printf("%lld ", e);
    //     }
    //     printf("\n");
    // }
    printf("%lld", dp[n][(1 << p) - 1]);
}