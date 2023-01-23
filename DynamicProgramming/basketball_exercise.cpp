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
    vi vec1(n);
    vi vec2(n);
    frange(i, n) scd(vec1[i]);
    frange(i, n) scd(vec2[i]);
    vector<lli> dp1(n);
    vector<lli> dp2(n);
    dp1[0] = vec1[0];
    dp2[0] = vec2[0];
    forr(i, 1, n)
    {
        dp1[i] = max(dp1[i - 1], dp2[i - 1] + vec1[i]);
        dp2[i] = max(dp2[i - 1], dp1[i - 1] + vec2[i]);
    }
    printf("%lld", max(dp1[n - 1], dp2[n - 1]));
}