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

int main()
{
    vb sieve(1e6 + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    vi prime;
    forr(i, 2, 1e6 + 1)
    {
        if (sieve[i])
        {
            prime.pb(i);

            for (lli j = lli(i) * i; j <= 1e6; j += i)
            {
                sieve[j] = false;
            }
        }
    }
    lli ans = 2;
    vll pref(prime.size() + 1);
    int mlen = 0;
    forr(i, 1, pref.size())
    {
        pref[i] = pref[i - 1] + prime[i - 1];
    }
    forr(l, 1, pref.size())
    {
        // auto itr = upper_bound(all(pref), pref[l - 1] + ans);
        forr(r, l + 1, pref.size())
        {
            lli sum = pref[r] - pref[l - 1];
            if (sum > 1e6)
                break;
            if (sum <= 1e6 && sieve[sum] && r - l + 1 > mlen)
            {
                ans = sum;
                mlen = r - l + 1;
            }
        }
    }
    cout << ans;
}