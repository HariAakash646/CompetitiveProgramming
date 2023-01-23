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

int log2func(int n)
{
    int x = 1;
    int i = 0;
    while (x < n)
    {
        x *= 2;
        i++;
    }
    return i;
}

int main()
{
    int n, q;
    scd(n);
    scd(q);
    seti vec;
    int a;
    frange(i, n)
    {
        scd(a);
        vec.insert(a);
    }
    n = vec.size();
    // vi dp(n + 1);
    // dp[1] = 0;
    // dp[2] = 1;
    // forr(i, 3, n + 1)
    // {
    //     dp[i] = dp[i / 2] + dp[i / 2 + (i % 2)] + 1;
    // }
    int out = log2func(n) + log2func(n / 2);
    if (out <= q)
        printf("YES");
    else
        printf("NO");
    printf("\n%d", out);
}