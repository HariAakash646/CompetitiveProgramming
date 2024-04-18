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

int m, k;
vi vec;

bool check(lli x)
{
    int kt = 1;
    lli curr = 0;
    for (auto e : vec)
    {
        if (e > x)
            return false;
        if (curr + e > x)
        {
            curr = 0;
            kt++;
        }
        curr += e;
    }
    return kt <= k;
}

int main()
{
    scd(m);
    scd(k);
    vec = vi(m);
    lli h = 0;
    frange(i, m)
    {
        scd(vec[i]);
        h += vec[i];
    }
    lli l = 0;
    while (l != h)
    {
        lli mid = (l + h) / 2;
        if (check(mid))
        {
            h = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    vvi seg(k);
    int curr = 0;
    int id = k - 1;
    for (int i = m - 1; i >= 0; i--)
    {

        if (curr + vec[i] > l)
        {
            curr = vec[i];
            id--;
            seg[id].pb(vec[i]);
        }
        else
        {
            curr += vec[i];
            seg[id].pb(vec[i]);
        }
        if (i - 1 == id - 1)
        {
            id--;
            for (int j = i - 1; j >= 0; j--)
            {
                seg[id].pb(vec[j]);
                id--;
            }
            break;
        }
    }
    frange(i, k)
    {
        vi v = seg[i];
        reverse(all(v));
        for (auto e : v)
        {
            printf("%d ", e);
        }
        if (i < k - 1)
            printf("/ ");
    }
}