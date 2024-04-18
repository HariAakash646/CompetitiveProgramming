#include <bits/stdc++.h>

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
typedef long double ld;

int n, m;
vi v1, v2;

bool check(int x)
{
    int i = 0;
    frange(j, m)
    {
        if (abs(v2[j] - v1[i]) <= x)
        {
            i++;
        }
        if (i >= n)
            break;
    }
    return i >= n;
}

int main()
{

    scd(n);
    scd(m);
    v1 = vi(n);
    v2 = vi(m);
    frange(i, n) scd(v1[i]);
    frange(i, m) scd(v2[i]);

    sort(all(v1));
    sort(all(v2));
    if (n > m)
    {
        swap(n, m);
        swap(v1, v2);
    }
    int lo = 0;
    int hi = 1e9;

    while (lo != hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
        {
            hi = mid;
        }
        else
            lo = mid + 1;
    }
    printf("%d", lo);
}