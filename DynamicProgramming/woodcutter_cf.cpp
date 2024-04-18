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
    int n;
    scd(n);
    vii vec(n + 1);
    vi pos(n + 2);
    pos[0] = -1e9 - 10;
    pos[n + 1] = 1e9 + 10;
    forr(i, 1, n + 1)
    {
        int a, b;
        scd(a);
        scd(b);
        vec[i] = {a, b};
        pos[i] = a;
    }
    sort(all(vec));
    sort(all(pos));
    vi dp(n + 1);
    forr(i, 1, n + 1)
    {
        if (pos[i - 1] < vec[i].f - vec[i].s)
        {
            dp[i] = dp[i - 1] + 1;
        }
        else if (pos[i + 1] > vec[i].f + vec[i].s)
        {
            dp[i] = dp[i - 1] + 1;
            pos[i] = pos[i] + vec[i].s;
        }
        else
        {
            dp[i] = dp[i - 1];
        }
    }
    printf("%d", dp[n]);
}