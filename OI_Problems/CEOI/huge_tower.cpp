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

const lli mod = 1e9 + 9;

int main()
{
    int n;
    lli d;
    scd(n);
    sclld(d);

    vll vec(n);
    frange(i, n) sclld(vec[i]);
    sort(all(vec));

    int i1 = 0;
    int i2 = 0;
    lli tot = 1;
    while (i1 < n)
    {
        while (vec[i1] - vec[i2] > d)
            i2++;
        tot = tot * (i1 - i2 + 1);
        tot %= mod;
        i1++;
    }
    printf("%lld", tot);
}