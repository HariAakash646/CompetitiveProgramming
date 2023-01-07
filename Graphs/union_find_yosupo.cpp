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
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vi disjoint;
vi height;

int findf(int a)
{
    if (disjoint[a] != a)
    {
        disjoint[a] = findf(disjoint[a]);
    }
    return disjoint[a];
}

void unionf(int a, int b)
{
    int roota = findf(a);
    int rootb = findf(b);
    int ha = height[roota];
    int hb = height[rootb];
    if (ha < hb)
    {
        disjoint[roota] = rootb;
        height[rootb]++;
    }
    else
    {
        disjoint[rootb] = roota;
        height[roota]++;
    }
}

int main()
{
    int n, q;
    scd(n);
    scd(q);
    disjoint = vi(n);
    height = vi(n, 1);
    frange(i, n)
    {
        disjoint[i] = i;
    }
    int t, u, v;
    frange(i, q)
    {
        scd(t);
        scd(u);
        scd(v);
        if (t == 0)
        {
            unionf(u, v);
        }
        else
        {
            if (findf(u) == findf(v))
                printf("1\n");
            else
                printf("0\n");
        }
    }
    return 0;
}