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

double h, c, tem;

bool check(lli x)
{
    double t0 = (h * x + c * (x - 1)) / (2 * x - 1);
    if (t0 >= tem)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        sclf(h);
        sclf(c);
        sclf(tem);
        double mid = (h + c) / 2;
        if (tem <= mid)
        {
            printf("2\n");
            continue;
        }
        lli l = 1;
        lli hi = 1e9;
        while (l != hi)
        {
            lli mid = (l + hi + 1) / 2;
            if (check(mid))
            {
                l = mid;
            }
            else
            {
                hi = mid - 1;
            }
        }

        double t0 = (h * l + c * (l - 1)) / (2 * l - 1);
        lli l1 = l + 1;
        double t1 = (h * l1 + c * (l1 - 1)) / (2 * l1 - 1);
        if (abs(tem - t0) <= abs(tem - t1))
            printf("%lld\n", 2 * l - 1);
        else
            printf("%lld\n", 2 * l1 - 1);
    }
}