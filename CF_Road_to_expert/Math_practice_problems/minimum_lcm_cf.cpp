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
    int x = sqrt(1e9) + 2;
    vb vec(x, true);
    vec[0] = false;
    vec[1] = false;
    forr(i, 1, x)
    {
        if (vec[i])
        {
            for (int j = i * i; j < x; j += i)
            {
                vec[j] = false;
            }
        }
    }
    vi prim;
    forr(i, 2, x)
    {
        if (vec[i])
        {
            prim.pb(i);
        }
    }
    frange(_, t)
    {
        int n;
        scd(n);
        bool done = false;
        for (auto e : prim)
        {
            if (n % e == 0)
            {
                printf("%d %d\n", n / e, n / e * (e - 1));
                done = true;
                break;
            }
        }
        if (!done)
        {
            printf("%d %d\n", n - 1, 1);
        }
    }
}