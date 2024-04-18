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
        int n, q;
        scd(n);
        scd(q);
        vll pref(n + 1);
        frange(i, n)
        {
            lli a;
            sclld(a);
            pref[i + 1] = pref[i] + a;
        }
        bool odd = false;
        if (pref[n] % 2)
        {
            odd = true;
        }
        frange(_, q)
        {
            lli l, r, k;
            sclld(l);
            sclld(r);
            sclld(k);
            lli v = k * (r - l + 1);
            if ((v % 2 == 1 && (pref[r] - pref[l - 1]) % 2 == 1) || (v % 2 == 0 && (pref[r] - pref[l - 1]) % 2 == 0))
            {
                if (odd)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else if (v % 2 != (pref[r] - pref[l - 1]) % 2)
            {
                if (odd)
                    printf("NO\n");
                else
                    printf("YES\n");
            }
        }
    }
}