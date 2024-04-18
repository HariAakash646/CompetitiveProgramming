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

int main()
{
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int n;
    scd(n);
    set<pair<pii, int>> ti;
    frange(i, n)
    {
        int a, t;
        scd(a);
        scd(t);
        ti.insert({{a, i}, t});
    }
    int ma = 0;
    int curr = (*ti.begin()).f.f;
    priority_queue<pair<pii, int>> pq;
    pq.push({{-(*ti.begin()).f.s, (*ti.begin()).f.f}, (*ti.begin()).s});
    ti.erase(ti.begin());
    // printf("%d\n", curr);
    while (pq.size() || ti.size())
    {
        if (pq.empty())
        {
            curr = (*ti.begin()).f.f;
            pq.push({{-(*ti.begin()).f.s, (*ti.begin()).f.f}, (*ti.begin()).s});
            ti.erase(ti.begin());
        }
        auto e = pq.top();
        pq.pop();
        ma = max(ma, curr - e.f.s);
        curr = max(e.f.s, curr) + e.s;
        // printf("%d\n", curr);
        if (ti.empty())
            continue;
        auto itr = ti.upper_bound(mp(mp(curr, -1), 0));
        // printf("%d %d %d\n", (*itr).f.f, (*itr).f.s, (*itr).s);
        // if (itr == ti.begin())
        // {
        //     pq.push({{-(*itr).f.s, (*itr).f.f}, (*itr).s});
        //     ti.erase(itr);
        // }
        // else

        for (auto i1 = ti.begin(); i1 != itr; i1++)
        {
            pq.push({{-(*i1).f.s, (*i1).f.f}, (*i1).s});
        }
        for (auto i1 = ti.begin(); i1 != itr;)
        {
            i1++;
            ti.erase(prev(i1));
        }
    }
    printf("%d", ma);
}