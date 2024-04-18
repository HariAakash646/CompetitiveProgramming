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

int findf(int x, vi &vec)
{
    while (x != vec[x])
    {
        x = vec[x];
    }
    return x;
}

void unionf(int x, int y, vi &vec, vi &siz)
{
    x = findf(x, vec);
    y = findf(y, vec);
    if (siz[x] < siz[y])
        swap(x, y);
    vec[y] = x;
    siz[x] = max(siz[x], siz[y] + 1);
}

int main()
{
    int n, k, l;
    scd(n);
    scd(k);
    scd(l);
    vi rail(n + 1);
    vi road(n + 1);
    vi sirail(n + 1, 1);
    vi siroad(n + 1, 1);
    forr(i, 1, n + 1)
    {
        rail[i] = i;
        road[i] = i;
    }
    frange(i, k)
    {
        int a, b;
        scd(a);
        scd(b);
        unionf(a, b, road, siroad);
    }
    frange(i, k)
    {
        int a, b;
        scd(a);
        scd(b);
        unionf(a, b, rail, sirail);
    }
    map<pii, int> cnt;
    forr(i, 1, n + 1)
    {
        cnt[mp(findf(i, road), findf(i, rail))]++;
    }
    forr(i, 1, n + 1)
    {
        printf("%d ", cnt[mp(findf(i, road), findf(i, rail))]);
    }
}