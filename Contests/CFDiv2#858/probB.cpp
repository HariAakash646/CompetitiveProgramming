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
typedef long double ld;

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
        int z = 0;
        int o = 0;
        int p = 0;
        int no = 0;
        for (auto e : vec)
        {
            if (e == 0)
            {
                z++;
            }
            else
            {
                p++;
                if (e == 1)
                    o++;
                else
                    no++;
            }
        }
        if (z - p >= 2)
        {
            if (no >= 1 || o == 0)
                printf("1\n");
            // else if (o == 1 && no == 1 && find(all(vec), 2) != vec.end())
            // {
            //     printf("3\n");
            // }
            else
                printf("2\n");
        }
        else
        {
            printf("0\n");
        }
    }
}