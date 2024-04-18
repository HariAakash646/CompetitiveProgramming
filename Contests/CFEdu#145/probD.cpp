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
        string seq;
        cin >> seq;
        int o = 0;
        int z = 0;
        bool curr = false;
        for (auto e : seq)
        {
            if (e == '1')
                curr = true;
            if (!curr)
                continue;
            if (e == '0')
                z++;
            else
                o++;
        }
        int z2 = 0;
        curr = false;
        for (auto e : seq)
        {
            if (e == '1')
            {
                if (!curr)
                    curr = true;
                else
                    break;
            }
            if (curr && e == '0')
                z2++;
        }
        reverse(all(seq));
        curr = false;
        int o2 = 0;
        for (auto e : seq)
        {
            if (e == '0')
            {
                break;
            }
            else
                o2++;
        }
        o -= o2;
        if (z >= o)
        {
            if (z2 == z)
            {
                printf("%lld\n", z2 * 1e12);
            }
            else
            {
                printf("%lld\n", z * lli(1e12 + 1));
            }
        }
        else
        {
            printf("%lld\n", o * lli(1e12 + 1));
        }
    }
}