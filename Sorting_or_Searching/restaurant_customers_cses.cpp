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
    int n;
    scd(n);
    vi vec(2 * n);
    vi arr(n);
    vi dep(n);
    frange(i, n)
    {
        scd(arr[i]);
        scd(dep[i]);
        vec[2 * i] = arr[i];
        vec[2 * i + 1] = dep[i];
    }
    sort(all(arr));
    sort(all(dep));
    sort(all(vec));
    mpii comp;
    forr(i, 1, 2 * n + 1)
    {
        comp[i] = vec[i - 1];
    }
    vi pref(2 * n + 1);
    forr(i, 1, 2 * n + 1)
    {
        pref[i] = pref[i - 1];
        if (binary_search(all(arr), comp[i]))
        {
            pref[i]++;
        }
        else if (binary_search(all(dep), comp[i]))
        {
            pref[i]--;
        }
    }
    printf("%d", *max_element(all(pref)));
}