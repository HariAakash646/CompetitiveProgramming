// Wrong
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

int mod = 1e9 + 7;

int main()
{
    int n;
    scd(n);
    vvi vec(n, vi(n));
    frange(i, n)
    {
        frange(j, n)
        {
            scd(vec[i][j]);
        }
    }
    vi dp1(1 << n);
    vi dp2(1 << n);
    dp1[0] = 1;
    dp2[0] = 1;
    forr(i, 1, 1 << n)
    {
        frange(j, n)
        {
            if (i & (1 << j))
            {
                frange(k, n)
                {
                    if (i & (1 << k))
                    {
                        if (vec[j][k])
                        {
                            dp1[i] += dp2[i ^ (1 << k)];
                            dp2[i] += dp1[i ^ (1 << j)];
                        }
                    }
                }
            }
        }
    }
    printf("%d", dp1[n]);
}