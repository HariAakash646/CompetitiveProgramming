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

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n, m, k;
        scd(n);
        scd(m);
        scd(k);
        if (n % 2 == 0)
        {
            if (m % 2 == 0)
            {
                if (k % 2 == 0)
                {
                    printf("YES\n");
                }
                else
                {
                    printf("NO\n");
                }
            }
            else
            {
                k -= ((m - 1) * n) / 2;
                if (k % 2 == 0)
                {
                    if (k > 0)
                    {
                        printf("NO\n");
                    }
                    else
                    {
                        printf("YES\n");
                    }
                }
                else
                {
                    printf("NO\n");
                }
            }
        }
        else
        {
            if (k < m / 2)
            {
                printf("NO\n");
            }
            else
            {
                k -= m / 2;
                if (k % 2 == 0)
                {
                    printf("YES\n");
                }
                else
                {
                    printf("NO\n");
                }
            }
        }
    }
}