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
    vi vec(n);
    vi count(1e7 + 5);
    vb prime(1e7 + 5, true);
    vi pref(1e7 + 5);
    frange(i, n)
    {
        scd(vec[i]);
        count[vec[i]]++;
    }
    int maxi;
    for (int i = 2; i <= 1e7; i++)
    {
        pref[i] = pref[i - 1];
        if (prime[i])
        {
            for (int j = i; j <= 1e7; j += i)
            {
                prime[j] = false;
                pref[i] += count[j];
            }
        }
        maxi = i;
    }
    int m;
    scd(m);
    frange(i, m)
    {
        int l, r;
        scd(l);
        scd(r);
        printf("%d\n", pref[min(r, maxi)] - pref[min(l - 1, maxi)]);
    }
}