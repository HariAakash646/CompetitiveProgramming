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
typedef vector<long long> vi;
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

lli inf = 1e15;

int main()
{
    int n, m, q;
    scd(n);
    scd(m);
    scd(q);
    vvi graph(n + 1, vi(n + 1, inf));
    forr(i, 1, n + 1, 1)
    {
        graph[i][i] = 0;
    }
    lli a, b, c;
    frange(i, m)
    {
        sclld(a);
        sclld(b);
        sclld(c);
        graph[a][b] = min(graph[a][b], c);
        graph[b][a] = min(graph[b][a], c);
    }
    forr(k, 1, n + 1, 1)
    {
        forr(r, 1, n + 1, 1)
        {
            forr(c, 1, n + 1, 1)
            {
                graph[r][c] = min(graph[r][c], graph[r][k] + graph[k][c]);
            }
        }
    }
    int h, k;
    frange(i, q)
    {
        scd(h);
        scd(k);
        if (graph[h][k] == inf)
            printf("%d\n", -1);
        else
            printf("%lld\n", graph[h][k]);
    }
}