#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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
    int n, k;
    scd(n);
    scd(k);
    vvi vec(2);
    printf("? ");
    forr(i, 1, k + 1)
    {
        printf("%d ", i);
    }
    printf("\n");
    fflush(stdout);
    int v1;
    scd(v1);
    vec[v1].pb(1);
    printf("? ");
    forr(i, 2, k + 2) printf("%d ", i);
    printf("\n");
    fflush(stdout);
    int v2;
    scd(v2);
    vec[v2].pb(k + 1);
    forr(i, 2, k + 1)
    {
        printf("? ");
        forr(j, 1, k + 2)
        {
            if (j != i)
                printf("%d ", j);
        }
        printf("\n");
        fflush(stdout);
        int v3;
        scd(v3);
        if (v1 == v3)
            vec[v2].pb(i);
        else
            vec[!v2].pb(i);
    }

    forr(i, k + 2, n - 1)
    {
        printf("? %d ", i);
        forr(j, 2, k + 1)
        {
            if (j != i)
                printf("%d ", j);
        }
        printf("\n");
        fflush(stdout);
        int v3;
        scd(v3);
        vec[v3].pb(i);
    }
    int i1 = 0;
    int i2 = 0;

    forr(i, 1, k + 1)
    {
        forr(j, 1, k + 1)
        {
            if (i != j)
            {
                if (find(all(vec[0]), i) != vec[0].end() && find(all(vec[0]), j) != vec[0].end())
                {
                    i1 = i;
                    i2 = j;
                    break;
                }
                if (find(all(vec[1]), i) != vec[1].end() && find(all(vec[1]), j) != vec[1].end())
                {
                    i1 = i;
                    i2 = j;
                    break;
                }
            }
        }
    }
    printf("? ")
}