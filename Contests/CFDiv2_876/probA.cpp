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
        int n, k;
        scd(n);
        scd(k);
        vi vec(n);
        int c = 0;
        frange(i, n)
        {
            if (((i + 1) + k - 1) / k > c)
            {
                vec[i] = 1;
                c++;
            }
        }
        int c2 = 0;
        forr(i, 1, n + 1)
        {
            if (vec[n - i] == 1)
                c2++;
            if ((i + k - 1) / k > c2)
            {
                vec[n - i] = 1;
                c2++;
            }
        }
        int ans = 0;
        for (auto e : vec)
        {
            if (e == 1)
                ans++;
        }
        printf("%d\n", ans);
    }
}