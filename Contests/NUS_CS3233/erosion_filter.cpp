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
    vector<ld> vec(n + 1);
    frange(i, n)
    {
        int a;
        scd(a);
        vec[i + 1] = a;
    }
    vector<ld> pref(n + 2);
    vector<ld> suff(n + 2);
    ld curr = pow(2, n - 1);
    forr(i, 1, n + 1)
    {
        pref[i] = pref[i - 1] + vec[i] / curr;
        curr *= 2;
    }
    curr = pow(2, n - 1);
    for (int i = n; i >= 1; i--)
    {
        suff[i] = suff[i + 1] + vec[i] / curr;
        curr *= 2;
    }
    ld rev = curr / 2;
    curr = 2;
    forr(i, 1, n + 1)
    {
        cout << suff[i + 1] + pref[i - 1] << " ";
        curr *= 2;
        rev /= 2;
    }
}