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
#define MP make_pair
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
    int n;
    scd(n);
    vi vec(n);
    vvi arr(n);
    vi bin;
    frange(i, n) scd(vec[i]);
    for (auto e : vec)
    {
        if (bin.empty())
        {
            bin.pb(e);
            arr[0].pb(e);
            continue;
        }
        int l = 0;
        int h = bin.size();
        while (l < h)
        {
            int mid = (l + h) / 2;
            if (bin[mid] < e)
            {
                h = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (e < *prev(bin.end()))
        {
            arr[bin.size()].pb(e);
            bin.pb(e);
        }
        else
        {
            arr[l].pb(e);
            bin[l] = e;
        }
    }
    for (auto v : arr)
    {
        if (v.empty())
            break;
        for (auto e : v)
        {
            printf("%d ", e);
        }
        printf("\n");
    }
}