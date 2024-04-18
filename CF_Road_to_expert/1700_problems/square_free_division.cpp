// Solving
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
#define MP make_pair
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

vi prime;

int fac(int x)
{
    mpii cnt;
    for (auto e : prime)
    {
        while (x % e == 0)
        {
            cnt[e]++;
            x /= e;
        }
    }
    if (x > 1)
        cnt[x]++;
    int out = 1;
    for (auto p : cnt)
    {
        if (p.s % 2)
        {
            out *= p.f;
        }
    }
    return out;
}

int main()
{
    vb sieve(1e4, true);
    sieve[0] = false;
    sieve[1] = false;
    forr(i, 2, 1e4 + 1)
    {
        if (sieve[i])
        {
            for (int j = i * i; j < 1e4; j += i)
            {
                sieve[j] = false;
            }
            prime.pb(i);
        }
    }
    int t;
    scd(t);
    frange(_, t)
    {
        int n, k;
        scd(n);
        scd(k);
        vi vec(n);
        frange(i, n)
        {
            int a;
            scd(a);
            vec[i] = fac(a);
        }
        seti st;
        int c = 1;
        for (auto e : vec)
        {
            if (st.find(e) != st.end())
            {
                st = {};
                c++;
            }
        }
        printf("%d\n", c);
    }
}