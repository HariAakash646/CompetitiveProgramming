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
    vvi dp(n + 1, vi(1e5 + 1, 1));
    vi vec(n);
    vi idx(1e5 + 1, -1);
    frange(i, n)
    {
        scd(vec[i]);
        idx[vec[i]] = i;
    }
    sort(all(vec));
    int ma = 0;
    for (auto e : vec)
    {
        forr(i, 1, 1e5 + 1)
        {
            if (e - i >= 0 && idx[e - i] != -1)
                dp[idx[e]][i] = dp[idx[e - i]][i] + 1;
            ma = max(ma, dp[idx[e]][i]);
        }
    }
    printf("%d", ma);
}