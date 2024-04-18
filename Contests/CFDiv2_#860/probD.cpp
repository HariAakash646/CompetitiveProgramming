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
        scd(n);
        multiset<lli> vec;
        lli ma = 0, mi = 0;
        frange(i, n)
        {
            lli a;
            sclld(a);
            vec.insert(a);
            ma = max(ma, a);
            mi = min(mi, a);
        }
        lli val = ma - mi;
        lli pref = 0;
        vll out;
        bool done = false;
        frange(i, n)
        {
            auto itr = vec.lower_bound(val - pref);
            if (itr == vec.begin())
            {
                printf("No\n");
                done = true;
                break;
            }
            itr--;
            out.pb(*itr);
            pref += *itr;
            vec.erase(itr);
        }
        if (done)
            continue;
        printf("Yes\n");
        for (auto e : out)
        {
            printf("%lld ", e);
        }
        printf("\n");
    }
}