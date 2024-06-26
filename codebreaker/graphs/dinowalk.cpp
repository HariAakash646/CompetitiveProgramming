#include <bits/stdc++.h>
#include <iostream>

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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int n;
    scd(n);
    vvi floyd(n, vi(n));

    frange(i, n)
    {
        frange(j, n)
        {
            scd(floyd[i][j]);
        }
    }

    frange(k, n)
    {
        frange(i, n)
        {
            frange(j, n)
            {
                floyd[i][j] = max(floyd[i][j], min(floyd[i][k], floyd[k][j]));
            }
        }
    }

    int mi = 1e6;
    frange(i, n)
    {
        frange(j, n)
        {
            if (i != j)
            {
                mi = min(mi, floyd[i][j]);
            }
        }
    }

    printf("%d", mi);
}