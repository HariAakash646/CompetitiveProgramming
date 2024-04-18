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

const int mod = 1e9 + 7;
int vec[int(1e6 + 1)];

int main()
{
    int m, n;
    scd(m);
    scd(n);
    int coins[m];
    frange(i, m) scd(coins[i]);
    sort(coins, coins + m);
    int l = n + 1;

    vec[0] = 1;
    forr(i, 1, n + 1)
    {
        vec[i] = 0;
        for (int k = 0; k < m; k++)
        {
            int j = coins[k];
            if (i - j >= 0)
            {
                vec[i] += vec[i - j];
                vec[i] %= mod;
            }
            else
                break;
        }
    }
    printf("%d", vec[n]);
    return 0;
}