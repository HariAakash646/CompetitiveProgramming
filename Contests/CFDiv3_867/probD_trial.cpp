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

int main()
{
    int n = 9;
    forr(i, 1, n + 1)
    {
        printf("\n\n%d\n", i);
        vi vec(i);
        forr(j, 1, i + 1) vec[j - 1] = j;
        do
        {
            vi pref(i);
            pref[0] = vec[0] % i;
            forr(j, 1, i) pref[j] = (pref[j - 1] + vec[j]) % i;
            vb vis(i);
            for (auto e : pref)
                vis[e % i] = true;
            bool done = true;
            for (auto e : vis)
            {
                if (!e)
                {
                    done = false;
                    break;
                }
            }
            if (done)
            {
                for (auto e : vec)
                {
                    printf("%d ", e);
                }
                printf("\n");
            }
        } while (next_permutation(all(vec)));
    }
}