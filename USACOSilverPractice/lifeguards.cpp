// Not working
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
    // freopen("lifeguards.in", "r", stdin);
    // freopen("lifeguards.out", "w", stdout);
    int n;
    scd(n);
    seti time;
    set<pii> arr;
    set<pii> dep;
    frange(i, n)
    {
        int a, b;
        scd(a);
        scd(b);
        time.insert(a);
        time.insert(b);
        arr.insert({a, i});
        dep.insert({b, i});
    }
    mpii alone;
    seti curr;
    int prev = 0;
    int tot = 0;
    int add = 0;
    for (auto e : time)
    {
        if (curr.size())
        {
            tot += e - prev + add;
            add = 0;
        }
        else
        {
            add = 1;
        }
        if (curr.size() == 1)
        {
            alone[*curr.begin()] += e - prev;
        }
        auto it1 = arr.lower_bound({e, 0});
        auto it2 = dep.lower_bound({e, 0});
        if (it1 != arr.end())
        {
            curr.insert((*it1).s);
        }
        else if (it2 != dep.end())
        {
            curr.erase((*it1).s);
        }
        prev = e;
    }
    int mi = 1e9 + 5;
    for (auto p : alone)
    {
        mi = min(mi, p.s);
    }
    printf("%d %d %d", tot, mi, tot - mi);
}