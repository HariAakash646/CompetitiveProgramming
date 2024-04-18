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
    int t;
    scd(t);
    frange(_, t)
    {
        int n, k;
        scd(n);
        scd(k);
        vll vec(n + 1);
        mseti s1, s2;
        lli tot = 0;
        frange(i, n)
        {
            sclld(vec[i + 1]);
            tot += vec[i + 1];
        }
        sort(all(vec));
        // pii r1 = {1, n};
        // pii r2 = {1, n};
        // vll dp1(k + 1);
        // vll dp2(k + 1);
        // dp1[0] = tot;
        // dp2[0] = tot;
        // forr(i, 1, k + 1)
        // {
        //     if (dp1[i - 1] - vec[r1.f] - vec[r1.f + 1] >= dp2[i - 1] - vec[r2.f] - vec[r2.f + 1])
        //     {
        //         dp1[i] = dp1[i - 1] - vec[r1.f] - vec[r1.f + 1];
        //         r1.f += 2;
        //     }
        //     else
        //     {
        //         dp1[i] = dp2[i - 1] - vec[r2.f] - vec[r2.f + 1];
        //         r2.f += 2;
        //     }
        //     if (dp1[i - 1] - vec[r1.s] >= dp2[i - 1] - vec[r2.s])
        //     {
        //         dp2[i] = dp1[i - 1] - vec[r1.s];
        //         r1.s--;
        //     }
        //     else
        //     {
        //         dp2[i] = dp2[i - 1] - vec[r2.s];
        //         r2.s--;
        //     }
        // }
        int k1 = k;
        lli ma = tot;
        lli ans;
        frange(i, k)
        {
            ma -= vec[n - i];
        }
        ans = ma;
        int curr = 1;
        forr(l, 1, k + 1)
        {
            ma += vec[n - (k - l)];
            ma -= vec[curr] + vec[curr + 1];
            curr += 2;
            ans = max(ma, ans);
        }
        printf("%lld\n", ans);
    }
}