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
    int t;
    scd(t);
    frange(_, t)
    {
        int m;
        scd(m);
        bool comp = false;
        bool d1 = false, d2 = false, d3 = false;
        frange(i, m)
        {
            int n;
            scd(n);
            frange(i, n)
            {
                int l, r;
                scd(l);
                scd(r);
                if ((l != 0) && (r != 0) && (i == 0))
                {
                    d1 = true;
                }
                if ((l == 0) && (r != 0) && (i == 0))
                {
                    d2 = true;
                }
                if ((l != 0) && (r == 0) && (i == 0))
                {
                    d3 = true;
                }
            }
            if (n == 1)
                comp = true;
        }
        if (comp)
        {
            printf("Almost Complete\n");
        }
        else if (d1 && d2 && d3)
        {
            printf("Almost Complete\n");
        }
        else
        {
            printf("No\n");
        }
    }
}