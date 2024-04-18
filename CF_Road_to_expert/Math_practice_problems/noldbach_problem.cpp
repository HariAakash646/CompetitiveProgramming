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
typedef vector<char> vc;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int n, k;
    scd(n);
    scd(k);
    vb isprime(n + 1, true);
    vi prim;
    for (int i = 2; i <= n; i++)
    {
        if (isprime[i])
        {
            prim.pb(i);
            for (int j = i * i; j <= n; j += i)
            {
                isprime[j] = false;
            }
        }
    }
    int t = 0;
    for (auto e : prim)
    {
        int x = e / 2;
        auto itr = upper_bound(all(prim), x);
        if (itr == prim.begin() || itr == prim.end())
        {
            continue;
        }
        int b = *itr;
        itr--;
        int a = *itr;
        if (a + b + 1 == e)
        {
            t++;
        }
    }
    if (t >= k)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}