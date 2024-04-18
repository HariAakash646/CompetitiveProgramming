#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
// #define mp make_pair
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

vi vec;
vll pref;
int n;

bool check(lli t, int x)
{
    lli c = 0;
    int k = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (c > t)
            return false;
        c += vec[i];
        if (c > t)
        {
            k++;
            c = c - t;
        }
        if (i == 0 && vec[i] <= t)
        {
            c = 0;
            k++;
        }
    }
    return k <= x && c == 0;
}

int main()
{

    scd(n);
    vec = vi(n);
    frange(i, n) scd(vec[i]);
    pref = vll(n + 1);
    for (int i = n - 1; i >= 0; i--)
    {
        pref[i] = pref[i + 1] + vec[i];
    }
    vll cnt(n + 1);
    forr(i, 1, n + 1)
    {
        lli lo = 0;
        lli hi = 1e9;
        while (lo != hi)
        {
            lli mid = (lo + hi) / 2;
            if (check(mid, i))
            {
                hi = mid;
            }
            else
                lo = mid + 1;
        }
        cnt[i] = lo;
        // printf("%lld ", cnt[i]);
    }
    // printf("\n");

    map<lli, int> mp;
    forr(i, 1, n + 1)
    {
        if (mp.find(cnt[i]) == mp.end())
            mp[cnt[i]] = i;
    }
    int q;
    scd(q);
    frange(_, q)
    {
        lli t;
        sclld(t);
        auto it = mp.upper_bound(t);
        if (it == mp.begin())
        {
            printf("-1\n");
            continue;
        }
        it--;
        printf("%d\n", (*it).s);
    }
}