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

bool cmp(pair<ld, int> x, pair<ld, int> y)
{
    if (x.f > y.f)
    {
        return true;
    }
    if (x.f == y.f)
        return x.s < y.s;
    else
        return false;
}

int main()
{
    int n;
    scd(n);
    vector<pair<ld, int>> vec(n);
    frange(i, n)
    {
        int a, b;
        scd(a);
        scd(b);
        vec[i] = {ld(a) / (ld(a) + ld(b)), i + 1};
    }
    sort(all(vec), cmp);
    for (auto p : vec)
    {
        printf("%d ", p.s);
    }
}