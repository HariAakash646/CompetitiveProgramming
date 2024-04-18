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

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int s1, s2;
        scd(s1);
        scd(s2);
        int c1, c2;
        scd(c1);
        scd(c2);
        int w1, w2;
        scd(w1);
        scd(w2);
        if (w2 > w1)
        {
            swap(c2, c1);
            swap(w2, w1);
        }
        if (s2 > s1)
            swap(s2, s1);
        lli ma = 0;
        frange(i, c2 + 1)
        {
            int v1 = s1;
            int v2 = s2;
            int k1 = min(s1 / w2, i);
            int k2 = min(s2 / w2, c2 - i);
            lli tot = k1 + k2;
            v1 -= k1 * w2;
            v2 -= k2 * w2;
            k1 = min(v1 / w1, c1);
            k2 = min(v2 / w1, c1 - k1);
            tot += k1 + k2;
            ma = max(ma, tot);
        }
        printf("%lld\n", ma);
    }
}