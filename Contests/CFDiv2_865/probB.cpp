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

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vvi vec(2, vi(n));
        vec[0][0] = 2 * n;
        forr(i, 1, n)
        {
            if (i % 2)
            {
                vec[1][i] = n + i;
            }
            else
            {
                vec[0][i] = n + i;
            }
        }
        forr(i, 0, n)
        {
            if (i % 2 == 0)
            {
                vec[1][i] = i + 1;
            }
            else
            {
                vec[0][i] = i + 1;
            }
        }
        if (n % 2)
        {
            vec[1][n - 1] = 1;
            vec[1][0] = n;
        }
        for (auto v : vec)
        {
            for (auto e : v)
            {
                printf("%d ", e);
            }
            printf("\n");
        }
    }
}