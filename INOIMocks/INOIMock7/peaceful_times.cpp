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
        int n, m, k;
        scd(n);
        scd(m);
        scd(k);

        if (m == 1)
        {
            vi vec(n + 1);
            frange(i, n)
            {
                scd(vec[i + 1]);
            }
            if (n == 3)
            {
                printf("-1\n");
                continue;
            }
            if (n == 2)
                printf("1 %d 2 %d\n", vec[1], vec[2]);
            else
                printf("1 %d 0 0\n", vec[1]);
        }
        else if (k == 2)
        {
            vi vec(n + 1);
            frange(i, n)
            {
                scd(vec[i + 1]);
            }
            int idx = 1;
            while (idx <= n)
            {
                if (vec[idx] >= 2)
                {
                    printf("%d %d %d %d\n", idx, 2, 0, 0);
                    vec[idx] -= 2;
                }
                else
                {
                    printf("%d %d %d %d\n", idx, 1, idx + 1, 1);
                    vec[idx] -= 1;
                    vec[idx + 1] -= 1;
                }
                if (vec[idx] == 0)
                    idx++;
                if (vec[idx] == 0)
                    idx++;
            }
        }
    }
}