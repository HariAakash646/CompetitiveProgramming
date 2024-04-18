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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fastio();
    int n, m;
    cin >> n >> m;

    vvi vec(n + 1, vi(m + 1));

    forr(i, 1, n + 1)
    {
        string row;
        cin >> row;
        forr(j, 1, m + 1)
        {
            if (row[j - 1] == '#')
                vec[i][j] = 1;
        }
    }

    vector<vb> dp1(n + 2, vb(m + 2)), dp2(n + 2, vb(m + 2));
    dp1[1][1] = true;
    forr(i, 1, n + 1)
    {
        forr(j, 1, m + 1)
        {
            if (!vec[i][j] && mp(i, j) != mp(1, 1))
            {
                dp1[i][j] = dp1[i - 1][j] || dp1[i][j - 1];
            }
        }
    }
    dp2[n][m] = true;
    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            if (!vec[i][j] && mp(i, j) != mp(n, m))
            {
                dp2[i][j] = dp2[i + 1][j] || dp2[i][j + 1];
            }
        }
    }
    vi cnt(n + m + 1);
    forr(i, 1, n + 1)
    {
        forr(j, 1, m + 1)
        {
            if (dp1[i][j] && dp2[i][j])
            {
                cnt[i + j]++;
            }
        }
    }
    int v = 2;
    forr(i, 3, n + m)
    {
        v = min(v, cnt[i]);
    }
    cout << v;
}