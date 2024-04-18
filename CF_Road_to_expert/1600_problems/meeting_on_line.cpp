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
vi pos, tim;

pair<bool, pii> check(int x)
{
    pii range = {0, 1e8};
    frange(i, n)
    {
        if (x < tim[i])
            return {false, mp(-1, -1)};
        int ma = pos[i] + (x - tim[i]);
        int mi = pos[i] - (x - tim[i]);
        if (mi > range.s)
            return {false, mp(-1, -1)};
        if (ma < range.f)
            return {false, mp(-1, -1)};
        range = mp(max(mi, range.f), min(ma, range.s));
    }
    return {true, range};
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {

        scd(n);
        pos = vi(n);
        tim = vi(n);
        int ma = 0;
        int mi = 1e8;
        frange(i, n)
        {
            scd(pos[i]);
            ma = max(ma, pos[i]);
            mi = min(mi, pos[i]);
        }
        frange(i, n)
        {
            scd(tim[i]);
        }
        int l = 0;
        int h = 2e8;
        pii out;
        while (l != h)
        {
            int mid = (l + h) / 2;
            auto p = check(mid);
            if (p.f)
            {
                h = mid;
                out = p.s;
            }
            else
            {
                l = mid + 1;
            }
        }
        bool fl = true;
        double x = l - 0.5;
        pair<double, double> range = {0.0, 1e8};
        frange(i, n)
        {
            if (x < tim[i])
            {
                printf("%d\n", out.s);
                fl = false;
                break;
            }
            double ma = pos[i] + (x - tim[i]);
            double mi = pos[i] - (x - tim[i]);
            if (mi > (range.s + 1e-3))
            {
                printf("%d\n", out.s);
                fl = false;
                break;
            }
            if (ma < (range.f - 1e-3))
            {
                printf("%d\n", out.s);
                fl = false;
                break;
            }
            range = mp(max(mi, range.f), min(ma, range.s));
        }
        if (fl)
            printf("%lf\n", range.f);
    }
}