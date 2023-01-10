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
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
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

int n, m;
vi disset;
vi sizev;

int findf(int x)
{
    if (x != disset[x])
        disset[x] = findf(disset[x]);
    return disset[x];
}

void unionf(int x, int y)
{
    int a = findf(x);
    int b = findf(y);
    if (sizev[a] > sizev[b])
        swap(a, b);
    disset[a] = b;
    sizev[b] += sizev[a];
}

bool same(int x, int y)
{
    return findf(x) == findf(y);
}

int main()
{
    scd(n);
    scd(m);
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    disset = vi(n + 1);
    forr(i, 1, n + 1, 1)
    {
        disset[i] = i;
    }
    sizev = vi(n + 1, 1);
    int a, b, c;
    frange(i, m)
    {
        scd(a);
        scd(b);
        scd(c);
        pq.push({c, pii{a, b}});
    }
    lli tot = 0;
    while (pq.size())
    {
        auto p = pq.top();
        pq.pop();
        if (!same(p.s.f, p.s.s))
        {
            tot += p.f;
            unionf(p.s.f, p.s.s);
        }
    }
    int ele = findf(1);
    forr(i, 2, n + 1, 1)
    {
        if (findf(i) != ele)
        {
            printf("IMPOSSIBLE");
            return 0;
        }
    }
    printf("%lld", tot);
}