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

vvi vec;
unordered_set<int> connections(int node)
{
    if (vec[node].empty())
        return unordered_set<int>{};
    unordered_set<int> ret(vec[node].begin(), vec[node].end());

    for (auto i : vec[node])
    {
        unordered_set<int> c = connections(i);
        ret.insert(c.begin(), c.end());
    }
    return ret;
}

int main()
{

    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    int n;
    scd(n);
    vec = vvi(n + 1);
    int a, b;
    frange(i, n - 1)
    {
        scd(a);
        scd(b);
        vec[b].PB(a);
    }
    vector<unordered_set<int>> all_con(n + 1);
    int m = 1;
    forr(i, 1, n + 1, 1)
    {
        all_con[i] = connections(i);
    }
    forr(i, 1, n + 1, 1)
    {
        m = int(all_con[i].size());
        if (m == n - 1)
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}