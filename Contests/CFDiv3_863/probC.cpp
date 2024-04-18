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
        vi b(n - 1);
        vi a(n);
        frange(i, n - 1)
        {
            scd(b[i]);
        }
        int j = 0;
        bool ski = true;
        a[0] = b[0];
        forr(i, 1, n - 1)
        {
            a[i] = min(b[i - 1], b[i]);

            // if (i >= 1)
            // {
            //     if (b[j - 1] < b[j] && ski)
            //     {
            //         a[i] = 0;
            //         a[i + 1] = b[i];
            //         i++;
            //         ski = false;
            //     }
            //     else
            //     {
            //         a[i] = b[i];
            //         j++;
            //     }
            // }
            // else
            // {
            //     a[i] = b[i];
            //     j++;
            // }
        }
        a[n - 1] = b[n - 2];
        for (auto e : a)
        {
            printf("%d ", e);
        }
        printf("\n");
    }
}