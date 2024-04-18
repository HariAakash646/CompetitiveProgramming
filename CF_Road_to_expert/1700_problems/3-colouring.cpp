#include <bits/stdc++.h>

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
    int n;
    scd(n);
    pii p1 = {1, 1};
    pii p2 = {1, 2};
    frange(i, n * n)
    {
        int a;
        scd(a);
        if (a != 1)
        {
            if (p1.f)
            {
                printf("1 %d %d\n", p1.f, p1.s);
                p1.s += 2;
                if (p1.s > n)
                {
                    p1.f += 1;
                    if (p1.f % 2)
                        p1.s = 1;
                    else
                        p1.s = 2;
                }
            }
            else
            {
                if (a == 2)
                    printf("3 %d %d\n", p2.f, p2.s);
                else
                    printf("2 %d %d\n", p2.f, p2.s);
                p2.s += 2;
                if (p2.s > n)
                {
                    p2.f += 1;
                    if (p2.f % 2)
                        p2.s = 2;
                    else
                        p2.s = 1;
                }
            }
        }
        else
        {
            if (p2.f)
            {
                printf("2 %d %d\n", p2.f, p2.s);
                p2.s += 2;
                if (p2.s > n)
                {
                    p2.f += 1;
                    if (p2.f % 2)
                        p2.s = 2;
                    else
                        p2.s = 1;
                }
            }
            else
            {
                printf("3 %d %d\n", p1.f, p1.s);
                p1.s += 2;
                if (p1.s > n)
                {
                    p1.f += 1;
                    if (p1.f % 2)
                        p1.s = 1;
                    else
                        p1.s = 2;
                }
            }
        }
        fflush(stdout);
        if (p1.f > n)
            p1 = {0, 0};
        if (p2.f > n)
            p2 = {0, 0};
    }
}