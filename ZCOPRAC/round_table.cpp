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
    vi vec(n);
    frange(i, n) scd(vec[i]);
    vi dpa1(n), dpa2(n), dpb1(n), dpb2(n);
    dpa1[0] = vec[0];
    dpa2[0] = 1e9 + 10;
    dpb1[0] = 1e9 + 10;

    forr(i, 1, n)
    {
        dpa1[i] = min(dpa1[i - 1], dpa2[i - 1]) + vec[i];
        dpa2[i] = dpa1[i - 1];
        dpb1[i] = min(dpb1[i - 1], dpb2[i - 1]) + vec[i];
        dpb2[i] = dpb1[i - 1];
    }
    printf("%d", min(dpb1[n - 1], min(dpa1[n - 1], dpa2[n - 1])));
}