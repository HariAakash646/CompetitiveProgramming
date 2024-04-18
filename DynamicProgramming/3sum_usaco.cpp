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

int MAX_N = 2e6;

int val_id(int x)
{
    return MAX_N + x;
}

int main()
{
    freopen("threesum.in", "r", stdin);
    freopen("threesum.out", "w", stdout);

    int n, q;
    scd(n);
    scd(q);
    vi vec(n);
    frange(i, n) scd(vec[i]);

    vll freq(4 * (MAX_N + 1));
    vector<vll> dp(n, vll(n));
    vector<vll> ways(n, vll(n));

    frange(i, n)
    {
        freq[val_id(vec[i + 1])]++;
        forr(j, i + 2, n)
        {
            ways[i][j] = freq[val_id(-(vec[i] + vec[j]))];
            freq[val_id(vec[j])]++;
        }
        forr(j, i + 1, n) freq[val_id(vec[j])]--;
    }

    forr(k, 2, n)
    {
        for (int l = 0; l + k < n; l++)
        {
            int r = l + k;
            dp[l][r] = dp[l + 1][r] + dp[l][r - 1] - dp[l + 1][r - 1] + ways[l][r];
        }
    }

    frange(_, q)
    {
        int a, b;
        scd(a);
        scd(b);
        a--;
        b--;
        printf("%lld\n", dp[a][b]);
    }
}