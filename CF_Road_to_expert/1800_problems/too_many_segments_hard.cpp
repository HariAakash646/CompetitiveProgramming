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
    int n, k;
    scd(n);
    scd(k);
    set<pair<pii, int>> seg;
    frange(i, n)
    {
        int l, r;
        scd(l);
        scd(r);
        seg.insert(mp(mp(l, r), i + 1));
    }
    set<pii> idx;
    int cnt = 0;
    vi out;
    forr(i, 1, 2e5 + 1)
    {
        while ((*seg.begin()).f.f == i)
        {
            idx.insert(mp((*seg.begin()).f.s + 1, (*seg.begin()).s));
            seg.erase(seg.begin());
        }
        while ((*idx.begin()).f == i)
        {
            idx.erase(idx.begin());
        }
        while (idx.size() > k)
        {
            cnt++;
            out.pb((*prev(idx.end())).s);
            idx.erase(prev(idx.end()));
        }
    }
    printf("%d\n", cnt);
    for (auto e : out)
    {
        printf("%d ", e);
    }
}