#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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
    int n, m;
    scd(n);
    scd(m);

    vll v1(n);
    vector<pair<lli, pii>> v2(m);

    forr(i, 0, n) sclld(v1[i]);
    lli mv = 0;
    lli mav = 0;
    forr(i, 0, m)
    {
        sclld(v2[i].f);
        scd(v2[i].s.f);
        scd(v2[i].s.s);
        mv += v2[i].s.f;
        mav += v2[i].s.s;
    }
    if (n < mv || n > mav)
    {
        printf("-1");
        return 0;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int id = 0;
    lli tot = 0;
    forr(i, 0, m)
    {
        frange(j, v2[i].s.f)
        {
            tot += abs(v1[id] - v2[i].f);
            id++;
        }
    }
    printf("%lld", tot);
}