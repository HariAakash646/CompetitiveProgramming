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

int mod = 998244353;

vi prime;

int fac(int x)
{
    lli cnt = 1;
    for (auto e : prime)
    {
        int c = 0;
        while (x % e == 0)
        {
            c++;
            x /= e;
        }
        cnt *= (c + 1);
    }
    int out = cnt % mod;
    if (x > 1)
    {
        out *= 2;
    }
    return out;
}

int main()
{
    int n;
    scd(n);
    int x = sqrt(n) + 5;
    vb sieve(x + 1, true);
    forr(i, 2, x + 1)
    {
        if (sieve[i])
        {
            prime.pb(i);
            for (int j = i * i; j <= x; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    vi vec(n + 1);
    vec[0] = 1;
    vi pref(n + 1);
    pref[0] = 0;
    forr(i, 1, n + 1)
    {
        vec[i] = pref[i - 1] + fac(i);
        vec[i] %= mod;
        // for (int j = 2 * i; j <= n; j += i)
        // {
        //     vec[j] += 1;
        //     vec[j] %= mod;
        // }
        pref[i] = pref[i - 1] + vec[i];
        pref[i] %= mod;
    }
    printf("%d", vec[n]);
}