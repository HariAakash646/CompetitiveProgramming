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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int n, m;
    scd(n);
    scd(m);
    vi vec(n);
    frange(i, n) scd(vec[i]);
    vii pos(n);
    int bsze = sqrt(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (i / bsze != (i + vec[i]) / bsze)
        {
            pos[i] = {1, i + vec[i]};
        }
        else
        {
            pos[i] = pos[i + vec[i]];
            pos[i].f++;
        }
    }
    frange(i, m)
    {
        int t;
        scd(t);
        if (t)
        {
            int a;
            scd(a);
            a--;
            int tot = 0;
            int pre = -1;
            while (a < n)
            {
                tot += pos[a].f;
                pre = a;
                a = pos[a].s;
            }
            printf("%d %d\n", pre + 1, tot);
        }
        else
        {
            int a, b;
            scd(a);
            scd(b);
            a--;
            vec[a] = b;
            for (int j = min(n - 1, ((a) / bsze + 1) * bsze - 1); j >= ((a) / bsze) * bsze; j--) // Some bug here
            {
                if (j / bsze != (j + vec[j]) / bsze)
                {
                    pos[j] = {1, j + vec[j]};
                }
                else
                {
                    pos[j] = pos[j + vec[j]];
                    pos[j].f++;
                }
            }
            // for(auto e : pos)
            //     printf("%d ", e.s);
        }
    }
}