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

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        lli n, k;
        sclld(n);
        sclld(k);
        vll vec(n);
        frange(i, n)
        {
            sclld(vec[i]);
        }
        if (k >= n)
        {
            lli tot = 0;
            for (auto e : vec)
                tot += e;
            tot += n * (k - n);
            tot += n * (n - 1) / 2;
            printf("%lld\n", tot);
        }
        else
        {

            lli curr = 0;
            int i1 = 0;
            int i2 = k - 1;
            frange(i, k)
            {
                curr += vec[i];
            }
            lli ma = curr;
            forr(i, k, n)
            {
                curr += vec[i];
                curr -= vec[i - k];
                ma = max(ma, curr);
            }
            ma += k * (k - 1) / 2;
            printf("%lld\n", ma);
        }
    }
}