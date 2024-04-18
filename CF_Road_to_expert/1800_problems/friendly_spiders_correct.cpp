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

vi prime;

vector<int> primefac(int x)
{
    vi vec;
    for (auto e : prime)
    {
        int i = 0;
        while (x % e == 0)
        {
            i++;
            x /= e;
            if (i == 1)
                vec.pb(e);
        }
        if (e > x)
            break;
    }
    if (x >= 2)
        vec.pb(x);
    return vec;
}

int main()
{
    int n;
    scd(n);
    vi vec(n + 1);
    vb vis(n + 1, false);
    int ma = 0;
    frange(i, n)
    {
        int a;
        scd(a);
        vec[i + 1] = a;
        ma = max(a, ma);
    }
    int sq = sqrt(ma);
    vb sieve(sq + 1, true);
    forr(i, 2, sq + 1)
    {
        if (sieve[i])
        {
            prime.pb(i);
            for (int j = i * i; j <= sq; j += i)
            {
                sieve[j] = false;
            }
        }
    }

    vvi graph(n + 1);
    vvi prgra(ma + 1);
    vi prpar(ma + 1);
    vb prvis(ma + 1, false);

    forr(i, 1, n + 1)
    {
        vi out = primefac(vec[i]);
        for (auto e : out)
        {
            graph[i].pb(e);
            prgra[e].pb(i);
        }
    }

    vi par(n + 1);
    int a, b;
    scd(a);
    scd(b);
    par[a] = a;
    vis[a] = true;
    if (a == b)
    {
        printf("1\n%d", a);
        return 0;
    }
    queue<pair<pii, int>> q;
    q.push(mp(mp(a, 0), 0));
    bool done = false;
    while (q.size())
    {
        auto p = q.front();
        q.pop();
        if (p.f.f == b && !p.s)
        {
            vi out;
            int x = p.f.f;
            while (par[x] != x)
            {
                out.pb(x);
                x = par[x];
            }

            printf("%d\n", p.f.s + 1);
            printf("%d ", a);
            reverse(all(out));
            for (auto e : out)
            {
                printf("%d ", e);
            }
            done = true;
            break;
        }
        if (p.s)
        {
            for (auto l : prgra[p.f.f])
            {
                if (!vis[l])
                {
                    q.push({{l, p.f.s + 1}, 0});
                    par[l] = prpar[p.f.f];
                    vis[l] = true;
                }
            }
        }
        else
        {
            for (auto l : graph[p.f.f])
            {
                if (!prvis[l])
                {
                    q.push({{l, p.f.s}, 1});
                    prpar[l] = p.f.f;
                    prvis[l] = true;
                }
            }
        }
    }
    if (!done)
        printf("-1\n");
}