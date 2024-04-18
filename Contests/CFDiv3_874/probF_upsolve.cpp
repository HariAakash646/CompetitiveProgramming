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
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

lli mod = 1e9 + 7;
lli inf = 1e15;

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n, m;
        scd(n);
        scd(m);
        vi vec(n);
        frange(i, n) scd(vec[i]);
        vector<pair<int, lli>> cnt;
        sort(all(vec));
        cnt.pb({vec[0], 1});
        forr(i, 1, n)
        {
            if (vec[i] == vec[i - 1])
            {
                cnt[cnt.size() - 1].s++;
            }
            else
            {
                cnt.pb({vec[i], 1});
            }
        }
        int x = cnt.size();
        vll suff(x + 1);
        // suff[x - 1] = cnt[x - 1].s;
        for (int i = x - 1; i >= 0; i--)
        {
            suff[i] = (suff[i + 1] + cnt[i].s) % mod;
        }
        vll suffprod(x + 1);
        for (int i = x - 1; i >= 0; i--)
        {
            suffprod[i] = (suffprod[i + 1] + cnt[i].s * suff[i + 1]) % mod;
        }
        lli tot = 0;
        // cnt.pb({1e9 + 7, 0});
        frange(i, x)
        {
            int id = upper_bound(all(cnt), mp(cnt[i].f + m, inf)) - cnt.begin() - 1;
            tot += (cnt[i].s * ((suffprod[i + 1] - suffprod[id + 1] - ((((suff[i + 1] - suff[id + 1] + mod) % mod) * suff[id + 1]) % mod) + 5 * mod) % mod)) % mod;
            tot %= mod;
        }
        printf("%lld\n", tot);
    }
}