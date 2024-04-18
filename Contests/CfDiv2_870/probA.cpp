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
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n;
        scd(n);
        vi vec(n);
        frange(i, n)
        {
            scd(vec[i]);
        }
        sort(all(vec));
        // int v = vec[0];
        // int c = 0;
        // for (auto e : vec)
        // {
        //     if (e > v)
        //         c++;
        // }
        // if (c >= v)
        //     printf("%d\n", c);
        // else
        // {
        //     bool done = false;
        //     for (auto e : vec)
        //     {
        //         if (e == n)
        //             done = true;
        //     }
        //     if (done)
        //         printf("-1\n");
        //     else
        //     {
        //         printf("%d\n", n);
        //     }
        // }
        bool done = false;
        frange(i, n + 1)
        {
            int c = 0;
            for (auto e : vec)
            {
                if (e > i)
                {
                    c++;
                }
            }
            if (c == i)
            {
                printf("%d\n", c);
                done = true;
                break;
            }
        }
        if (!done)
            printf("-1\n");
    }
}