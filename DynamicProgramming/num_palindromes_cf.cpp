// Not working
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
    string str;
    cin >> str;
    int sz = str.size();
    int q;
    scd(q);
    vvi dp(sz, vi(sz));
    frange(i, sz)
    {
        frange(j, sz)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else if (i == j - 1 && str[i] == str[j])
            {
                dp[i][j] = 1;
            }
            else if (str[i] == str[j] && i < j)
            {
                dp[i][j] = dp[i + 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    vvi pal(sz + 1, vi(sz + 1));
    for (int i = sz - 1; i >= 0; i--)
    {
        for (int j = 0; j <= sz; j++)
        {
            int a, b, c;
            a = 0;
            b = 0;
            c = 0;
            if (i + 1 < sz)
                a = pal[i + 1][j];
            if (j - 1 >= 0)
                b = pal[i][j - 1];
            if (i + 1 < sz && j - 1 >= 0)
                c = pal[i + 1][j - 1];
            pal[i][j] = a + b - c + dp[i][j];
        }
    }
    int a, b;
    frange(i, q)
    {
        scd(a);
        scd(b);
        printf("%d\n", pal[a - 1][b - 1]);
    }
}