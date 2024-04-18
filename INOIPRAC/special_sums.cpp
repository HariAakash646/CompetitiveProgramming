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

int main()
{
    int n;
    scd(n);
    vi a(n + 1), b(n + 1);
    forr(i, 1, n + 1)
    {
        scd(a[i]);
    }
    forr(i, 1, n + 1) scd(b[i]);
    vll pref1(n + 1), pref(n + 1);

    forr(i, 1, n + 1)
    {
        pref1[i] = pref1[i - 1] + b[i];
        pref[i] = pref1[i - 1] + a[i];
    }
    vll prefr1(n + 1), prefr(n + 1);
    prefr1[0] = prefr[0] = pref1[n];
    forr(i, 1, n + 1)
    {
        prefr1[i] = prefr1[i - 1] + b[i];
        prefr[i] = prefr1[i - 1] + a[i];
    }
    lli ma1 = -1e18;
    lli ma2 = -1e18;
    lli v = -1e18;
    forr(i, 1, n + 1)
    {
        v = max(v, (lli)a[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        v = max(v, ma1 - pref1[i] + a[i]);
        ma1 = max(ma1, pref[i]);
        // printf("%d %d\n", i, v);
    }
    // printf("\n");
    forr(i, 1, n + 1)
    {
        v = max(v, ma2 - pref1[i] + a[i]);
        // printf("%lld %lld ", ma2, pref1[i]);
        ma2 = max(ma2, prefr[i]);
        // printf("%d %d\n", i, v);
    }
    printf("%lld", v);
}