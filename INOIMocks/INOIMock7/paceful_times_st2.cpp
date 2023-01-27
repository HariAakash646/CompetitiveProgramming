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

        vii vec(n + 1);
        int ma = 0;
        int secm = 0;
        frange(i, n)
        {
            scd(vec[i + 1].f);
            vec[i + 1].s = i + 1;
            if (vec[i + 1].f > ma)
            {
                secm = ma;
                ma = vec[i + 1].f;
            }
            else if (vec[i + 1].f > secm)
            {
                secm = vec[i + 1].f;
            }
        }
        if (n == 4)
        {
            if (ma >= k)
            {
                printf("-1\n");
                continue;
            }
            if (ma + secm > k)
            {
                printf("-1\n");
                continue;
            }
        }
        if (n == 3)
        {
            if (ma > k)
            {
                printf("-1\n");
                continue;
            }
        }
        sort(all(vec));
        reverse(all(vec));
        int idx = 0;
        while (idx < n)
        {
            if (vec[idx].f >= k)
            {
                printf("%d %d %d %d\n", vec[idx].s, k, 0, 0);
                vec[idx].f -= k;
            }
            else
            {
                printf("%d %d %d %d\n", vec[idx].s, vec[idx].f, vec[idx + 1].s, k - vec[idx].f);

                vec[idx + 1].f -= (k - vec[idx].f);
                vec[idx].f = 0;
                idx++;
            }

            if (idx < n && (vec[idx].f <= 0))
                idx++;
        }
    }
}