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
    int t1 = 0, t2 = 0, t3 = 0;
    vll v1, v2, v3;

    frange(i, n)
    {
        int t;
        lli x;
        scd(t);
        sclld(x);
        if (t == 0)
            v1.pb(x);
        else if (t == 1)
            v2.pb(x);
        else
            v3.pb(x);
    }
    sort(all(v1), greater<>());
    sort(all(v2), greater<>());
    sort(all(v3), greater<>());
    t1 = v1.size();
    t2 = v2.size();
    t3 = v3.size();
    vll pr1(t1), pr2(t2), pr3(t3);
    if (t1 > 0)
        pr1[0] = v1[0];
    forr(i, 1, t1) pr1[i] = pr1[i - 1] + v1[i];

    if (t2 > 0)
        pr2[0] = v2[0];
    forr(i, 1, t2) pr2[i] = pr2[i - 1] + v2[i];

    if (t3 > 0)
        pr3[0] = v3[0];
    forr(i, 1, t3) pr3[i] = pr3[i - 1] + v3[i];
    lli ma = 0;
    frange(i, min(t2 + 1, m + 1))
    {
        auto it = lower_bound(all(pr3), i);
        int c = it - pr3.begin() + 1;
        if (i == 0)
            c = 0;
        lli v = 0;
        if (c + i > m)
            continue;
        if (it != pr3.end())
        {
            if (i != 0 && t2)
                v += pr2[i - 1];
        }
        if (m - (c + i) > 0 && t1)
            v += pr1[min(t1 - 1, m - (c + i) - 1)];
        ma = max(ma, v);
    }
    printf("%lld", ma);
}