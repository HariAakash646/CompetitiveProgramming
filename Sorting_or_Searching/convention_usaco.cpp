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

vi vec;
bool check(int x, int m, int c)
{
    auto itr = vec.begin();
    int co = 0;
    while (itr != vec.end())
    {
        itr = min(itr + c, upper_bound(all(vec), *itr + x));
        co++;
    }
    if (co <= m)
        return true;
    else
        return false;
}

int main()
{
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int n, m, c;
    scd(n);
    scd(m);
    scd(c);

    vec = vi(n);
    frange(i, n)
    {
        scd(vec[i]);
    }
    sort(all(vec));
    int l = 0;
    int h = vec[n - 1] - vec[0];
    while (l < h)
    {
        int mid = (l + h) / 2;
        if (check(mid, m, c))
        {
            h = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%d", l);
}