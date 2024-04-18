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

int mod = 998244353;

int main()
{
    int n, k;
    scd(n);
    scd(k);

    int x = sqrt(2 * n) + 1;
    k--;
    vi prev(n + 1);
    vi curr(n + 1);
    prev[0] = 1;
    vi tot(n + 1);
    forr(j, 1, x + 1)
    {
        forr(i, 1, n + 1)
        {
            if (i - (k + j) >= 0)
            {
                curr[i] = (prev[i - (k + j)] + curr[i - (k + j)]) % mod;
            }
            tot[i] += curr[i];
            tot[i] %= mod;
        }
        prev = curr;
        curr = vi(n + 1);
    }

    forr(i, 1, n + 1)
    {

        printf("%d ", tot[i]);
    }
}