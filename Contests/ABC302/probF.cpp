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

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vb vis(n);
    seti ele;
    vvi sets(n);
    vector<seti> pres(m + 1);
    frange(i, n)
    {
        int a;
        scd(a);
        sets[i] = vi(a);
        frange(j, a)
        {
            scd(sets[i][j]);
            pres[sets[i][j]].insert(i);
        }
    }
    queue<pii> q;
    q.push({1, 0});
    vb visnum(m + 1);

    while (q.size())
    {
        auto p = q.front();
        int e = p.f;
        if (e == m)
        {
            printf("%d", p.s - 1);
            return 0;
        }
        q.pop();
        if (visnum[e])
            continue;
        visnum[e] = true;
        for (auto st : pres[e])
        {
            if (!vis[st])
            {
                vis[st] = true;
                for (auto x : sets[st])
                {
                    if (!visnum[x])
                    {
                        pres[x].erase(st);
                        q.push({x, p.s + 1});
                    }
                }
            }
        }
    }
    printf("-1");
}