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
#define PB push_back
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

int n, k;
vi vec;
bool f(int x, int y)
{
    long long t = 0;
    forr(i, x, y, 1)
    {
        t += vec[y] - vec[i];
        if (t > k)
            return false;
    }
    return true;
}

int main()
{

    scd(n);
    scd(k);
    vec = vi(n);
    frange(i, n)
    {
        scd(vec[i]);
    }
    if (n == 1)
    {
        cout << vec[0] + k;
        return 0;
    }
    sort(vec.begin(), vec.end());
    int med = vec[n / 2];
    int med_idx = n / 2;
    int lo = med_idx;
    int h = n - 1;
    while (lo < h)
    {
        int mid = (h + lo + 1) / 2;
        bool res = f(med_idx, mid);
        if (res)
        {
            lo = mid;
        }
        else
        {
            h = mid - 1;
        }
    }
    int t = 0;
    int out = vec[lo];
    forr(i, med_idx, lo, 1)
    {
        t += vec[lo] - vec[i];
    }
    k -= t;
    out += k / (lo - med_idx + 1);
    cout << out;

    return 0;
}