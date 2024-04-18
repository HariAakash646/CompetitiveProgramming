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
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int n;
    scd(n);
    vi vec(n);
    frange(i, n) scd(vec[i]);
    vvll dp1(n, vll(n));
    vvll dp2(n, vll(n));
    frange(i, n)
    {
        for (int j = 0; j + i < n; j++)
        {
            if (i == 0)
            {
                dp1[j][j] = vec[j];
                dp2[j][j] = -vec[j];
            }
            else
            {
                dp1[j][j + i] = max(vec[j] + dp2[j + 1][j + i], vec[j + i] + dp2[j][j + i - 1]);
                dp2[j][j + i] = min(dp1[j + 1][j + i] - vec[j], dp1[j][j + i - 1] - vec[j + i]);
            }
        }
    }
    printf("%lld", dp1[0][n - 1]);
}