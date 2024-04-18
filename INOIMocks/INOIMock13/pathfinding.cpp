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
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

bool cmp(pair<pii, int> x, pair<pii, int> y)
{
    if (x.f.s < y.f.s)
        return true;
    else
        return false;
}

int main()
{
    int n;
    scd(n);
    vector<pair<pii, int>> vec(n);
    frange(i, n)
    {
        scd(vec[i].f.s);
        scd(vec[i].f.f);
        vec[i].s = i + 1;
    }
    sort(all(vec));
    vector<vector<pii>> graph(n + 1);
    graph[0].pb({vec[0].s, (vec[0].f.f + vec[0].f.s)});
    frange(i, n)
    {
        auto e = vec[i];
        graph[e.s].pb();
    }
}