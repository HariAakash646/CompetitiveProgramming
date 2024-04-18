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

int n;
lli t;
vector<pair<pii, int>> vec;

bool check(int x)
{
    int c = 0;
    lli tot = 0;
    int idx = 0;
    while (c < x)
    {
        if (vec[idx].f.s >= x)
        {
            c++;
            tot += vec[idx].f.f;
        }
        idx++;
        if (idx >= n && c < x)
            return false;
    }
    return tot <= t;
}

int main()
{

    scd(n);
    sclld(t);
    vec = vector<pair<pii, int>>(n);
    frange(i, n)
    {
        scd(vec[i].f.s);
        scd(vec[i].f.f);
        vec[i].s = i + 1;
    }
    sort(all(vec));
    int l = 0;
    int h = n;
    while (l != h)
    {
        int mid = (l + h + 1) / 2;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            h = mid - 1;
        }
    }
    printf("%d\n%d\n", l, l);
    int c = 0;
    int idx = 0;
    while (c < l)
    {
        if (vec[idx].f.s >= l)
        {
            c++;
            printf("%d ", vec[idx].s);
        }
        idx++;
    }
}