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

vll po10(14, 1);
vll vec(14);
lli check(lli x)
{
    if (x < 4)
    {
        return 0;
    }
    int n = to_string(x).size() - 1;
    if (n == 0)
        return 1;
    int v = x / po10[n];
    if (v < 4)
    {
        return v * vec[n] + check(x % po10[n]);
    }
    else
    {
        return (v - 1) * vec[n] + po10[n] + check(x % po10[n]);
    }
}

int main()
{
    int t;
    scd(t);

    vec[1] = 1;
    lli po = 1;
    po10[1] = 10;
    forr(i, 2, 14)
    {
        vec[i] = 10 * vec[i - 1] + po * 8LL;
        po10[i] = po10[i - 1] * 10;
        po *= 10;
    }
    frange(_, t)
    {
        lli k;
        sclld(k);
        lli lo = k;
        lli hi = 4 * k;
        // while(lo != hi) {
        //     lli mid = (lo + hi)/2;
        // }
        printf("%lld\n", check(k));
    }
}