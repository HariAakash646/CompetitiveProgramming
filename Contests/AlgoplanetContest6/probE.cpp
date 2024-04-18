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
        n *= 2;
        mseti vec;
        frange(i, n)
        {
            int a;
            scd(a);
            vec.insert(a);
        }
        bool over = false;
        int v;
        int d = 1;
        int c = 1;
        int x = *prev(vec.end());
        int og = x;
        vec.erase(vec.find(x));
        mseti vec2 = vec;

        for (auto e : vec)
        {
            x = og;
            vii out;
            vec2.erase(vec2.find(e));
            v = e + x;
            out.pb(mp(e, x));
            bool done = false;
            while (vec2.size())
            {
                int x2 = *prev(vec2.end());
                vec2.erase(vec2.find(x2));
                if (vec2.find(x - x2) != vec2.end())
                {
                    vec2.erase(vec2.find(x - x2));
                    out.pb(mp(x2, x - x2));
                }
                else
                {
                    done = true;
                    break;
                }
                x = x2;
            }
            if (!done)
            {
                printf("YES\n");
                printf("%d\n", v);
                for (auto p : out)
                {
                    printf("%d %d\n", p.f, p.s);
                }
                over = true;
                break;
            }
            vec2 = vec;
        }
        // out.pb({vec[i1].f, vec[i2].f});
        // v = vec[i1].f + vec[i2].f;
        if (!over)
            printf("NO\n");
    }
}