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

int n, m, a, b;
vi vec;

bool check(int x)
{
    vi curr(x);
    frange(i, x) curr[i] = vec[i];
    reverse(all(curr));
    int sec = a - 1 + abs(b - a);
    if (a < x)
    {
        sec -= 2 * (x - a);
    }
    int c = 0;
    for (auto e : curr)
    {
        sec -= 2;
        if (e <= sec)
            c++;
    }
    return c >= x;
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {

        scd(n);
        scd(m);
        scd(a);
        scd(b);
        vec = vi(m);
        frange(i, m) scd(vec[i]);
        sort(all(vec));
        if (a > b)
            swap(a, b);
        int hi = min(m, abs(b - a));
        int lo = 0;
        while (hi != lo)
        {
            int mid = (lo + hi + 1) / 2;
            if (check(mid))
                lo = mid;
            else
                hi = mid - 1;
        }
        printf("%d\n", lo);
    }
}