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
        vi vec(n);
        frange(i, n) scd(vec[i]);
        int mi = 1e9;
        forr(i, vec[0] / k, vec[0] + 1)
        {

            int ma = i;
            if (i == 0)
                ma = vec[n - 1] / k;
            else
            {
                forr(j, 0, n)
                {
                    ma = max(ma, vec[j] / min(k, vec[j] / i));
                    // printf("%d %d %d\n", vec[j], vec[j] / min(k, vec[j] / i), i);
                }
            }
            mi = min(mi, ma - i);
            // printf("\n");
        }
        printf("%d\n", mi);
    }
}