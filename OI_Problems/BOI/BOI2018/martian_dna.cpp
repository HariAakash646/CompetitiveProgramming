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

int n, k, r;
vi vec, val;
int tot = 0;

bool check(int x)
{
    vi cnt(k);
    int t = 0;
    frange(i, x)
    {
        t -= min(val[vec[i]], cnt[vec[i]]);
        cnt[vec[i]]++;
        t += min(val[vec[i]], cnt[vec[i]]);
    }
    if (t == tot)
        return true;
    forr(i, x, n)
    {
        t -= min(val[vec[i - x]], cnt[vec[i - x]]);
        cnt[vec[i - x]]--;
        t += min(val[vec[i - x]], cnt[vec[i - x]]);
        t -= min(val[vec[i]], cnt[vec[i]]);
        cnt[vec[i]]++;
        t += min(val[vec[i]], cnt[vec[i]]);
        if (t == tot)
            return true;
    }
    return false;
}

int main()
{

    scd(n);
    scd(k);
    scd(r);
    vec = vi(n);
    val = vi(k);
    frange(i, n) scd(vec[i]);
    frange(i, r)
    {
        int a, v;
        scd(a);
        scd(v);
        val[a] = v;
        tot += v;
    }
    int lo = 1;
    int hi = n;
    while (lo != hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    if (check(lo))
        printf("%d", lo);
    else
        printf("impossible");
}