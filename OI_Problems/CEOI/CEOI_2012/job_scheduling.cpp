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

vvi vec;
int n, d, m;

bool check(int x)
{
    queue<int> q;
    forr(i, 1, n + 1)
    {
        for (auto e : vec[i])
            q.push(i);
        int curr = x;
        while (curr && q.size())
        {
            int p = q.front();
            q.pop();
            if (i - p > d)
                return false;
            curr--;
        }
    }
    return true;
}

int main()
{

    scd(n);
    scd(d);
    scd(m);
    vec = vvi(n + 1);
    forr(i, 1, m + 1)
    {
        int a;
        scd(a);
        vec[a].pb(i);
    }
    int hi = m;
    int lo = 1;

    while (hi != lo)
    {
        int mid = (hi + lo) / 2;
        if (check(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    queue<pii> q;
    vvi out(n + 1);
    forr(i, 1, n + 1)
    {
        for (auto e : vec[i])
            q.push({i, e});
        int curr = lo;
        while (curr && q.size())
        {
            pii p = q.front();
            q.pop();
            out[i].pb(p.s);
            curr--;
        }
    }
    printf("%d\n", lo);
    forr(i, 1, n + 1)
    {
        for (auto e : out[i])
        {
            printf("%d ", e);
        }
        printf("0\n");
    }
}