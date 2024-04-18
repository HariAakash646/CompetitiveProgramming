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

int main()
{
    int t;
    scd(t);
    int n = 5e6;
    vi sieve(n + 1);

    forr(i, 2, n + 1)
    {
        if (sieve[i] == 0)
        {
            for (int j = i; j <= n; j += i)
            {
                int v = j;
                while (v % i == 0)
                {
                    sieve[j]++;
                    v /= i;
                }
            }
        }
    }
    // frange(i, 10) printf("%d ", sieve[i]);
    // printf("\n");
    vll pref(n + 1);
    forr(i, 1, n + 1)
    {
        pref[i] = pref[i - 1] + sieve[i];
    }
    frange(_, t)
    {
        int a, b;
        scd(a);
        scd(b);
        printf("%lld\n", pref[a] - pref[b]);
    }
}