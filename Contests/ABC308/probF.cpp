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
    int n, m;
    scd(n);
    scd(m);
    vll vec(n);
    frange(i, n) sclld(vec[i]);
    vector<pair<lli, lli>> disc(n);
    frange(i, n) sclld(disc[i].f);
    frange(i, n) sclld(disc[i].s);
    vector<mseti> dis(n);
    sort(all(vec));
    sort(all(disc));
    int id = 0;
    lli red = 0;
    frange(i, n)
    {
        while (disc[id].f < vec[i])
        {
            if (i > 0)
                dis[i - 1].insert(disc[id].s);
            id++;
            if (id >= m)
                break;
        }
        if (id >= m)
            break;
        dis[i].insert(disc[id].s);
    }
    mseti val;
    for (int i = n - 1; i >= 0; i--)
    {
        for (auto e : dis[i])
            val.insert(e);
        if (val.size())
        {
            red += vec[i] - *prev(val.end());
            val.erase(prev(val.end()));
        }
        else
            red += vec[i];
    }
    printf("%lld", red);
}