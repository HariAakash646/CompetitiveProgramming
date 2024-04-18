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
    int n, a, b;
    scd(n);
    scd(a);
    scd(b);

    vector<pair<int, pii>> vec(n);

    frange(i, n)
    {
        scd(vec[i].s.f);
    }
    frange(i, n)
    {
        scd(vec[i].s.s);
    }
    frange(i, n)
    {
        vec[i].f = vec[i].s.f - vec[i].s.s;
    }
    sort(all(vec));
    int tot = 0;
    frange(i, b)
    {
        tot += vec[i].s.s;
    }
    forr(i, b, n)
    {
        tot += vec[i].s.f;
    }
    printf("%d", tot);
}