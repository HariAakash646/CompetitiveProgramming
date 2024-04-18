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

int main()
{

    int m, n;
    scd(m);
    scd(n);
    vi coins(m);
    frange(i, m) scd(coins[i]);
    vi vec(n + 1, 1e9);
    vec[0] = 0;
    forr(i, 1, n + 1, 1)
    {
        for (auto j : coins)
        {
            if (i - j >= 0)
                vec[i] = min(vec[i], vec[i - j] + 1);
        }
    }
    if (vec[n] == 1e9)
        cout << -1;
    else
        cout << vec[n];
    return 0;
}