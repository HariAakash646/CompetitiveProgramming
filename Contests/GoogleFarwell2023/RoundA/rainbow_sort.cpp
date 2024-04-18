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
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vb vis(1e5 + 1);
        vi out;
        int pre = 0;
        bool done = false;
        printf("Case #%d: ", _ + 1);
        frange(i, n)
        {
            int a;
            scd(a);
            if (done)
                continue;
            if (vis[a])
            {
                if (pre != a)
                {
                    printf("IMPOSSIBLE");
                    done = true;
                }
            }
            else
                out.pb(a);
            vis[a] = true;
            pre = a;
        }
        if (!done)
        {
            for (auto e : out)
            {
                printf("%d ", e);
            }
        }
        printf("\n");
    }
}