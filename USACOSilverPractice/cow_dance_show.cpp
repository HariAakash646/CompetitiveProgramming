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

int n, t;
vi vec;

bool check(int k)
{
    seti stage;
    for (auto e : vec)
    {
        if (stage.size() < k)
        {
            stage.insert(e);
        }
        else
        {
            stage.insert(e + *stage.begin());
            stage.erase(stage.begin());
        }
    }
    if (*prev(stage.end()) <= t)
        return true;
    else
        return false;
}

int main()
{
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    scd(n);
    scd(t);
    vec = vi(n);
    frange(i, n)
    {
        scd(vec[i]);
    }
    int l = 1;
    int h = n;
    int sol = n;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (check(mid))
        {
            sol = min(mid, sol);
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%d", sol);
}