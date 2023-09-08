#include <bits/stdc++.h>
// #include "light.h"

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

long long n = 1;
set<lli> pre;
bool fir = true;
lli pv;

void prepare()
{
}

vector<long long> get()
{
    set<long long> r;
    r.insert(n);
    lli i = n;
    lli d = 1;
    i -= d;
    while (i > 0)
    {
        if (fir || *pre.lower_bound(i - pv) <= i)
            r.insert(i);
        d *= 2;
        i -= d;
    }
    i = 1;
    while (i <= n)
    {
        if (fir || *pre.lower_bound(i - pv) <= i)
            r.insert(i);
        i *= 2;
    }
    // r.insert((p + 1) / 2);
    r.insert(1);
    vector<lli> out;
    pre = r;
    fir = false;
    for (auto e : r)
        out.pb(e);
    return out;
}

pair<long long, vector<long long>> join(long long p)
{
    n = n + p;
    pv = 5 * p;
    return {5 * p, get()};
}

pair<long long, vector<long long>> leave(long long p)
{
    n -= p;
    pv = 5 * p;
    return {5 * p, get()};
}
