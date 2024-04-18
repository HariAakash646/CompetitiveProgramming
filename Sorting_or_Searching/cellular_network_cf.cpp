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

vi city, tow;
int n, m;

bool check(int r)
{
    int idx1 = 0;
    int idx2 = 0;
    frange(i, m - 1)
    {

        while (city[idx1] <= tow[i] + r)
        {
            idx1++;
            if (idx1 >= n)
                break;
        }
        while (city[idx2] < tow[i + 1] - r)
        {
            idx2++;
            if (idx2 >= n)
                break;
        }

        if (idx1 < idx2)
            return false;
        idx2 = idx1;
    }
    return true;
}

int main()
{

    scd(n);
    scd(m);
    city = vi(n);
    tow = vi(m);
    frange(i, n)
    {
        scd(city[i]);
    }
    frange(i, m)
    {
        scd(tow[i]);
    }
    int l = max({tow[0] - city[0], city[n - 1] - tow[m - 1], 0});
    int h = max(city[n - 1] - tow[0], tow[m - 1] - city[0]);
    while (l != h)
    {
        int mid = (l + h) / 2;
        bool out = check(mid);
        if (out)
            h = mid;
        else
            l = mid + 1;
        if (l > h)
        {
            printf("-1");
            return 0;
        }
    }
    printf("%d", l);
}