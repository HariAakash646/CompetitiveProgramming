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
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        lli n;
        sclld(n);
        lli v = (2 * n * (2 * n + 1));
        bool done = false;
        forr(i, n, 3 * n + 1)
        {
            lli i2 = i + n;
            lli i1 = i;
            lli v2 = i2 * (i2 + 1);
            lli v1 = i1 * (i1 + 1);
            if (v2 - v1 == v)
            {
                printf("YES\n");
                i1++;
                int med = (i1 + i2) / 2;
                int curr = med;
                forr(j, 1, n + 1)
                {
                    if (curr >= i1)
                    {
                        printf("%d %d\n", j, curr - j);
                        curr--;
                    }
                    else
                    {
                        curr = i2;
                        printf("%d %d\n", j, curr - j);
                        curr--;
                    }
                }
                done = true;
                break;
            }
        }
        if (!done)
            printf("NO\n");
    }
}