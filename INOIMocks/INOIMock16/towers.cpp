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
    int n, q;
    scd(n);
    scd(q);
    vi vec(n);
    frange(i, n)
    {
        scd(vec[i]);
    }
    frange(_, q)
    {
        int t;
        scd(t);
        if (t == 1)
        {
            int i, x;
            scd(i);
            scd(x);
            vec[i - 1] = x;
        }
        if (t == 2)
        {
            int i;
            scd(i);
            printf("%d\n", vec[i - 1]);
        }
        if (t == 3)
        {
            int l, r;
            scd(l);
            scd(r);
            frange(i, n)
            {
                if (l <= vec[i] && vec[i] <= r)
                {
                    if (vec[i] - l > r - vec[i])
                    {
                        vec[i] = r + 1;
                    }
                    else
                    {
                        vec[i] = l - 1;
                    }
                }
            }
        }
    }
}