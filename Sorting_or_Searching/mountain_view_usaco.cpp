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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
#define f first
#define s second

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

bool comp(const pii &x, const pii &y)
{
    if (x.f > y.f)
        return true;
    else if (x.f == y.f)
        return x.s >= y.s;
    else
        return false;
}

int main()
{

    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    int n;
    scd(n);
    vector<pii> vec(n);
    int x, y;
    frange(i, n)
    {
        scd(x);
        scd(y);
        vec[i].f = y - x;
        vec[i].s = x + y;
    }
    sort(vec.begin(), vec.end(), comp);

    int tot = n;
    auto itr = vec.begin();
    int max_s = 0;
    for (auto e : vec)
    {
        if (e.s <= max_s)
            tot -= 1;
        max_s = max(max_s, e.s);
    }
    cout << tot;

    return 0;
}