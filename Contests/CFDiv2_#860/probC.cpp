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

lli gcd(lli a, lli b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vector<pair<lli, lli>> vec(n);
        frange(i, n)
        {
            sclld(vec[i].f);
            sclld(vec[i].s);
        }
        int c = 1;
        lli curr = vec[0].s;
        lli curgc = vec[0].f;
        forr(i, 1, n)
        {
            lli hcf = gcd(max(curr, vec[i].s), min(curr, vec[i].s));
            lli lcm = (curr * vec[i].s) / hcf;
            lli v1 = lcm / curr;
            lli v2 = lcm / vec[i].s;
            if (curgc % v1 == 0 && vec[i].f % v2 == 0)
            {
                curgc /= v1;
                vec[i].f /= v2;
                curgc = gcd(max(curgc, vec[i].f), min(curgc, vec[i].f));
                curr = lcm;
            }
            else
            {
                c++;
                curr = vec[i].s;
                curgc = vec[i].f;
            }
        }
        printf("%d\n", c);
    }
}