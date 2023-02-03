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
    int n, r;
    scd(n);
    scd(r);

    // if (n == 1)
    {
        bool one = false, zero = false;
        frange(_, r)
        {
            int t, k;
            scd(t);
            scd(k);
            frange(__, k)
            {
                int a;
                scd(a);
            }
            if (t == 1)
                one = true;
            else
                zero = true;
        }
        if (zero && !one)
            printf("Yes\n0\n");
        else if (one && !zero)
            printf("Yes\n1\n1");
        else if (!zero && !one)
            printf("Yes\n0\n");
        else
            printf("No");
    }
}