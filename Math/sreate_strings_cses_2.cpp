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

lli mod = 1e9 + 7;

lli exp(lli a, lli b, lli m)
{
    lli prod = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            prod = (prod * a) % m;
        }
        b /= 2;
        a = (a * a) % m;
    }
    return prod;
}

int main()
{
    string str;
    cin >> str;
    int n = 0;
    map<char, int> mp;
    for (auto e : str)
    {
        n++;
        mp[e]++;
    }
    vector<lli> fact(n + 1, 1);
    vector<lli> inv(n + 1, 1);
    forr(i, 1, n + 1, 1)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = exp(fact[i], mod - 2, mod);
    }
    lli num = fact[n];
    for (auto p : mp)
    {
        num = (num * fact[p.second]) % mod;
    }
    cout << num << "\n";
    return 0;
}