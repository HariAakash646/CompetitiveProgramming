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
    int t;
    scd(t);
    frange(_, t)
    {
        int n, m;
        scd(n);
        scd(m);
        vi vec(n * m);
        frange(i, n * m)
        {
            scd(vec[i]);
        }
        sort(all(vec));
        int tot1 = vec[n * m - 1] * (n * m);
        tot1 -= vec[n * m - 1];
        if (n > m)
            swap(n, m);
        tot1 -= vec[1] * (n - 1);
        tot1 -= vec[0] * (m - 1) * n;

        int tot2 = -(vec[0] * (n * m));
        tot2 += vec[0];
        tot2 += vec[n * m - 2] * (n - 1);
        tot2 += vec[n * m - 1] * (m - 1) * n;
        printf("%d\n", max(tot1, tot2));
    }
}