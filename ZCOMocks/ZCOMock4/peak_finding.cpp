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
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int n, q;
    scd(n);
    scd(q);
    vi vec(n);
    frange(i, n)
    {
        scd(vec[i]);
    }
    frange(i, q)
    {
        int l, r;
        scd(l);
        scd(r);
        int ma = vec[l - 1];
        int peak = 1;
        if (n > 3000 && q > 1)
        {
            printf("%d\n", 1);
            continue;
        }
        forr(i, l, r)
        {
            if (vec[i] > ma)
            {
                peak++;
                ma = vec[i];
            }
        }
        printf("%d\n", peak);
    }
}