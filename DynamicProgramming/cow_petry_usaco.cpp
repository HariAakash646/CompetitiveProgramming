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

void usaco()
{
    freopen("poetry.in", "r", stdin);
    freopen("poetry.out", "w", stdout);
}

void fastio()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

int mod = 1e9 + 7;

lli binexp(lli x, lli p)
{
    if (p == 0)
        return 1;
    if (p % 2)
    {
        return x * binexp(x, p - 1) % mod;
    }
    else
    {
        lli v = binexp(x, p / 2);
        return v * v % mod;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    usaco();
    int n, m, k;
    cin >> n >> m >> k;
    // scd(n);
    // scd(m);
    // scd(k);
    vii vec(n + 1);
    forr(i, 1, n + 1)
    {
        cin >> vec[i].f >> vec[i].s;
        // scd(vec[i].f);
        // scd(vec[i].s);
    }
    vector<vi> dp(n + 1, vi(k + 1));
    vi dp2(k + 1);
    dp2[0] = 1;
    dp[0][0] = 1;
    forr(j, 1, k + 1)
    {
        forr(i, 1, n + 1)
        {
            if (j - vec[i].f >= 0)
            {
                dp[i][j] += dp2[j - vec[i].f];
                dp[i][j] %= mod;
                dp2[j] += dp[i][j];
                dp2[j] %= mod;
            }
        }
    }
    vll cnt(n + 1);
    forr(i, 1, n + 1)
    {
        cnt[vec[i].s] += dp[i][k];
        cnt[vec[i].s] %= mod;
    }
    vll co(26);
    frange(i, m)
    {
        char c;
        cin >> c;
        co[c - 'A']++;
    }
    lli out = 1;
    vll val(26);
    frange(i, 26)
    {
        if (co[i] == 0)
        {
            val[i] = 1;
            continue;
        }
        forr(j, 1, n + 1)
        {
            if (cnt[j] == 0)
                continue;
            val[i] += binexp(cnt[j], co[i]);
            val[i] %= mod;
        }
    }
    frange(i, 26)
    {
        out *= val[i];
        out %= mod;
    }
    cout << out;
}