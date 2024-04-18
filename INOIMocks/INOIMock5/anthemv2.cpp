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
    vi vec(n + 1);
    forr(i, 1, n + 1)
    {
        scd(vec[i]);
    }
    vector<lli> mult(n + 1);
    forr(i, 1, n + 1)
    {
        mult[i] = mult[i - 1];
        if (i <= n / 2)
            mult[i]++;
        else if (i == n / 2 + 1)
            mult[i] += (n % 2);
        else
            mult[i]--;
    }
    lli tot = 0;
    forr(i, 1, n + 1)
    {
        tot += mult[i] * vec[i];
    }
    printf("%lld", tot);
}