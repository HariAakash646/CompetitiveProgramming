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

vi graph;
vi info;
vb vis;

int succ(int node)
{
    return graph[node];
}

void floyd_algo(int node)
{
    int a = succ(node);
    int b = succ(succ(node));
    int i = 1;
    if (info[a])
    {
        info[node] = info[a] + i;
        return;
    }
    while (a != b)
    {
        if (info[a])
        {
            info[node] = info[a] + i;
            return;
        }
        a = succ(a);
        b = succ(succ(b));
        ++i;
    }
    a = node;
    while (a != b)
    {
        a = succ(a);
        b = succ(b);
    }
    int first = a;
    a = node;
    int len = 0;
    while (a != first)
    {
        a = succ(a);
        ++len;
    }
    a = first;
    b = succ(a);
    int cyclen = 1;
    while (a != b)
    {
        b = succ(b);
        ++cyclen;
    }
    int totlen = len + cyclen;
    a = node;
    while (a != first)
    {
        info[a] = totlen;
        vis[a] = true;
        a = succ(a);
        totlen--;
    }
    info[a] = cyclen;
    vis[a] = true;
    a = succ(a);
    while (a != first)
    {
        info[a] = cyclen;
        vis[a] = true;
        a = succ(a);
    }
}

int main()
{
    int n;
    scd(n);
    graph = vi(n + 1);
    vis = vb(n + 1, false);
    info = vi(n + 1, 0);
    frange(i, n)
    {
        scd(graph[i + 1]);
    }
    forr(i, 1, n + 1)
    {
        if (!vis[i])
        {
            floyd_algo(i);
        }
    }
    forr(i, 1, n + 1)
    {
        printf("%d ", info[i]);
    }
}
