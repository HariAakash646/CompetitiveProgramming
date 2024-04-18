// Correct approach. Implem bugs. Do later.
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

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        lli ti, a, b;
        scd(n);
        sclld(ti);
        sclld(a);
        sclld(b);
        vii vec(n);
        int eas = 0;
        int har = 0;
        frange(i, n)
        {
            int x;
            scd(x);
            vec[i].s = x;
            if (x)
                har++;
            else
                eas++;
        }
        frange(i, n)
        {
            scd(vec[i].f);
        }
        sort(all(vec));
        vec.pb({ti, 0});
        lli tot = 0;
        int ma = 0;
        int i = 0;
        for (auto p : vec)
        {
            int v = i;
            int tim = p.f - 1;
            lli curr = tot;
            int c = (tim - tot) / a;
            if (c >= 0)
            // continue;
            {
                if (c > eas)
                {
                    v += eas;
                    curr += eas * a;
                    c = (tim - curr) / b;
                    v += min(har, c);
                }
                else
                {
                    v += c;
                    curr += c * a;
                }
                ma = max(v, ma);
                printf("%d %d %d %d %d %d\n", tim, curr, v, eas, har, c);
            }
            if (p.s)
            {
                tot += b;
                har--;
            }
            else
            {
                tot += a;
                eas--;
            }
            i++;
        }
        printf("%d\n", ma);
    }
}