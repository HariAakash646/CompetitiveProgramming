// Not working.
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
typedef vector<char> vc;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int sq = 1e5 + 10;
    vi siev(sq + 1);
    vi prim;
    forr(i, 2, sq + 1)
    {
        if (!siev[i])
        {
            prim.pb(i);
            for (int j = 2; i * j <= sq; j++)
            {
                siev[i * j] = i;
            }
        }
    }
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vi vec(n);
        int ma = 0;
        frange(i, n)
        {
            scd(vec[i]);
            ma = max(ma, vec[i]);
        }

        bool done = false;
        for (auto e : prim)
        {
            bool prev = false;
            for (auto p : vec)
            {
                if (p % e == 0)
                {
                    if (prev)
                    {
                        done = true;
                        printf("YES\n");
                        break;
                    }
                    prev = true;
                }
            }
            if (done)
                break;
        }
        if (!done)
        {
            printf("NO\n");
        }
    }
}