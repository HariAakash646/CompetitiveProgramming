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

int main()
{
    int n;
    int x;
    scd(n);
    scd(x);
    vi v1(n / 2), v2((n + 1) / 2);
    frange(i, n / 2) scd(v1[i]);
    frange(i, (n + 1) / 2) scd(v2[i]);
    vi st1, st2;
    frange(i, 1 << (n / 2))
    {
        int c = 0;
        frange(j, n / 2)
        {
            if (i & (1 << j))
            {
                c += v1[j];
                if (c > x)
                    break;
            }
        }
        if (c <= x)
            st1.pb(c);
    }
    frange(i, 1 << ((n + 1) / 2))
    {
        int c = 0;
        frange(j, (n + 1) / 2)
        {
            if (i & (1 << j))
            {
                c += v2[j];
                if (c > x)
                    break;
            }
        }
        if (c <= x)
            st2.pb(c);
    }
    lli t = 0;
    sort(all(st1));
    sort(all(st2));
    for (auto p : st1)
    {
        t += upper_bound(all(st2), x - p) - lower_bound(all(st2), x - p);
    }
    printf("%lld", t);
}