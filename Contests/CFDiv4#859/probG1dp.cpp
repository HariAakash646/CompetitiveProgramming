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
        bool done = false;
        sort(all(vec));
        vi dp(5001, 0);
        dp[0] = 1;
        if (vec[0] == 1)
        {
            dp[1] = 1;
        }
        else
        {
            printf("NO\n");
            done = true;
            continue;
        }
        vi dp_tmp = dp;
        forr(i, 1, n)
        {
            if (!dp[vec[i]])
            {
                printf("NO\n");
                done = true;
                break;
            }
            forr(j, 0, 5001)
            {
                if (dp[j] == 1)
                {
                    if (j + vec[i] <= 5000)
                    {
                        dp_tmp[j + vec[i]] = 1;
                    }
                }
            }
            dp = dp_tmp;
        }
        if (!done)
        {
            printf("YES\n");
        }
    }
}