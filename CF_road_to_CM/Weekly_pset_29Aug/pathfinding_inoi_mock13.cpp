#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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

int bsze;

struct Query
{
    int x, y, idx;
    bool operator<(Query other) const
    {
        if (x / bsze < other.x / bsze)
            return true;
        else if (x / bsze > other.x / bsze)
            return false;
        else
        {
            int v = x / bsze;
            if (v % 2)
                return y > other.y;
            else
                return y < other.y;
        }
    }
};

struct Query2

    int
    main()
{
    int n;
    scd(n);
    vector<Query> vec(n);
    frange(i, n)
    {
        scd(vec[i].x);
        scd(vec[i].y);
        vec[i].idx = i + 1;
    }
    bsze = sqrt(n);
    sort(all(vec));
    for (auto p : vec)
        printf("%d ", p.idx);
}