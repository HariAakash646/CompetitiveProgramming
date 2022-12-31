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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back

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
    int t;
    scd(t);
    frange(i, t)
    {
        int n;
        scd(n);
        int k;
        scd(k);
        vi vec(n);
        frange(j, n) vec[j] = j + 1;
        sort(vec.begin(), vec.end());
        vi perm(n, 0);
        int j_tmp = 0;
        if (k == 1)
        {
            for (auto e : vec)
                printf("%d ", e);
            printf("\n");
            continue;
        }
        if (n % 2 == 1)
        {
            perm[n - 1] = vec[n / 2];
            j_tmp = 0;
        }
        for (int j = 0; j < n / 2; j++)
        {
            int min_ele = vec[j];
            int max_ele = vec[n - j - 1];
            while (perm[j_tmp] != 0)
            {
                j_tmp++;
            }
            perm[j_tmp + 1] = min_ele;
            perm[j_tmp] = max_ele;
        }

        for (auto e : perm)
            printf("%d ", e);
        printf("\n");
    }
    return 0;
}