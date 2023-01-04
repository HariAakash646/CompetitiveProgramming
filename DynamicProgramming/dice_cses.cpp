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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define pb push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int mod = 1e9 + 7;

int main()
{

    int n;
    scd(n);
    vi vec(n + 1, 0);
    forr(i, 1, min(n + 1, 7), 1)
    {
        vec[i] = 1;
        forr(j, 1, i, 1)
        {
            vec[i] = (vec[i] + vec[j]) % mod;
        }
    }
    forr(i, 7, n + 1, 1)
    {
        forr(j, 1, 7, 1)
        {
            vec[i] = (vec[i] + vec[i - j]) % mod;
        }
    }
    cout << vec[n];
}