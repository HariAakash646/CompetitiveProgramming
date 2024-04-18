// Must solve later. Interesting problem.
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
typedef vector<char> vc;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int mod = 998244353;

int main()
{
    int t;
    scd(t);
    frange(i, t)
    {
        int l, r;
        scd(l);
        scd(r);
        int out = r / l;
        int curr = 1;
        int c = 0;
        int tot = 0;
        while (curr <= out)
        {
            curr *= 2;
            c++;
        }
        curr /= 2;
        forr(i, l, r + 1)
        {
            out = r / i;
            if (out >= curr)
            {
                tot++;
                int tmp = curr * l;
                lli a1 = c;
                int cou = 0;
                while (curr >= pow(2, cou + 1) && tmp / 2 * 3 <= r)
                {
                    tot += a1;
                    tot %= mod;
                    cou++;
                    a1 = (a1 * (c - cou)) % mod;
                    tmp /= 2;
                    tmp *= 3;
                }
            }
            else
                break;
            tot %= mod;
        }
        // out = r / l;
        // curr = 1;
        // int c1 = 0;
        // while (curr <= out)
        // {
        //     curr *= 3;
        //     c1++;
        // }
        // curr /= 3;
        // if (c1 == c)
        // {
        //     tot++;
        //     forr(i, l + 1, r + 1)
        //     {
        //         out = r / i;
        //         if (out >= curr)
        //         {
        //             tot++;
        //         }
        //         else
        //             break;
        //         tot %= mod;
        //     }
        // }
        printf("%d %d\n", c, tot);
    }
}