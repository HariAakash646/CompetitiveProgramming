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

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    int n;
    scd(n);
    vi vec(n + 1);
    set<pii> vert;
    vb vis(n + 1, false);
    frange(i, n)
    {
        int a;
        scd(a);
        vec[i + 1] = a;
        vert.insert({i + 1, a});
    }

    vi par(n + 1);
    int a, b;
    scd(a);
    scd(b);
    par[a] = a;
    if (a == b)
    {
        printf("1\n%d", a);
        return 0;
    }
    queue<pair<pii, int>> q;
    q.push(mp(mp(a, vec[a]), 1));
    bool done = false;
    while (q.size())
    {
        auto p = q.front();
        q.pop();
        vii er;
        for (auto e : vert)
        {
            if (gcd(max(e.s, p.f.s), min(e.s, p.f.s)) != 1)
            {
                er.pb(e);
                q.push(mp(e, p.s + 1));
                par[e.f] = p.f.f;
                if (e.f == b)
                {
                    vi out;
                    int x = e.f;
                    while (par[x] != x)
                    {
                        out.pb(x);
                        x = par[x];
                    }
                    printf("%d\n", p.s + 1);
                    printf("%d ", a);
                    reverse(all(out));
                    for (auto e : out)
                    {
                        printf("%d ", e);
                    }
                    done = true;
                    break;
                }
            }
        }
        for (auto e : er)
            vert.erase(e);
        if (done)
            break;
    }
    if (!done)
        printf("-1\n");
}