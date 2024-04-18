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

vector<pair<lli, lli>> vec;
int n, m;

bool check(lli d, int n)
{
    lli st = vec[0].f;
    int c = 1;
    int idx = 0;
    frange(i, n - 1)
    {
        lli curr = st + d;
        while (vec[idx].s < curr)
        {
            idx++;
            if (idx >= m)
                return false;
        }
        st = max(vec[idx].f, curr);
    }
    return true;
}

int main()
{
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    scd(n);
    scd(m);
    vec = vector<pair<lli, lli>>(m);
    frange(i, m)
    {
        lli a, b;
        sclld(a);
        sclld(b);
        vec[i] = {a, b};
    }
    sort(all(vec));
    lli l = 1;
    lli h = vec[m - 1].s - vec[0].f + 1;
    while (l < h)
    {
        lli mid = l + (h - l + 1) / 2;
        if (check(mid, n))
        {
            l = mid;
        }
        else
        {
            h = mid - 1;
        }
    }
    printf("%lld", l);
}