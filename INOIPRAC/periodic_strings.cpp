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

int n, m;

int main()
{
    scd(n);
    scd(m);
    vll pow2f(n + 1);
    pow2f[0] = 1;
    forr(i, 1, n + 1) pow2f[i] = (pow2f[i - 1] * 2) % m;
    lli out = 0;
    vll sub(n + 1);
    forr(i, 2, n)
    {
        if (n % i == 0)
        {
            out += pow2f[i] - sub[i] + m - 2 + m;
            out %= m;
            for (int j = 2 * i; j <= n; j += i)
            {
                sub[j] += pow2f[i] - sub[i] + m - 2 + m;
                sub[j] %= m;
            }
        }
    }
    if (n >= 2)
        out += 2;
    out %= m;
    printf("%lld", (pow2f[n] - out + m) % m);
}