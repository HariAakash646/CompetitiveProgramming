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
    vi vec(n);
    frange(i, n) scd(vec[i]);
    sort(all(vec));
    vll pref(n);
    pref[0] = vec[0];
    forr(i, 1, n)
    {
        pref[i] = vec[i] + pref[i - 1];
    }
    forr(i, 1, n - 1)
    {
        if (pref[i] > vec[n - 1])
        {
            printf("%d", i + 2);
            return 0;
        }
    }
    printf("-1");
}