#include <bits/stdc++.h>
#include <iostream>

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
#define MP make_pair
#define pb push_back
#define f first
#define s second
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    string num;
    cin >> num;
    vi vec(num.size());
    frange(i, num.size())
    {
        vec[i] = num[i] - '0';
    }
    vvi dp(3, vi(num.size()));
    if (vec[0] % 3 == 0)
    {
        dp[0][0] = 1;
    }
    int tot = vec[0];
    bool done = false;
    forr(i, 1, num.size())
    {
        tot += vec[i];
        if (tot >= 3)
        {
            done = true;
        }
        dp[0][i] = dp[(3 - vec[i] % 3) % 3][i - 1] + (done || vec[i] == 0);
        dp[1][i] = dp[(4 - vec[i] % 3) % 3][i - 1];
        dp[2][i] = dp[(5 - vec[i] % 3) % 3][i - 1];
    }
    printf("%d", max({dp[0][num.size() - 1], dp[1][num.size() - 1], dp[2][num.size() - 1]}));
}