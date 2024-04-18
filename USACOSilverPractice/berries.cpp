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
    freopen("berries.in", "r", stdin);
    freopen("berries.out", "w", stdout);
    int n, k;
    scd(n);
    scd(k);
    multiset<int> ober;
    frange(i, n)
    {
        int a;
        scd(a);
        ober.insert(a);
    }

    int ma = 0;
    frange(eac, *prev(ober.end()) + 1)
    {
        mseti ber = ober;
        int out = 0;
        forr(i, 1, k + 1)
        {
            auto itr = prev(ber.end());
            int v = *itr;
            if (i > k / 2)
            {
                out += min(v, eac);
            }
            ber.erase(itr);
            ber.insert(v - min(v, eac));
            ma = max(ma, out);
        }
    }

    printf("%d", ma);
}