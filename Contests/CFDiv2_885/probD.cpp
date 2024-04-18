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

vi cnt;
lli v1;
vi vec(10);
int x;

lli eval(lli v, lli k, lli d)
{
    lli tot = v * (k - d);
}

int main()
{
    scd(t);
    frange(_, t)
    {
        lli v, k;
        sclld(v);
        sclld(k);
        lli r = k;
        lli l = 0;

        x = v % 10;
        int i = 1;

        while (!vec[x])
        {
            vec[x] = i;
            x = (x + x) % 10;
            i++;
        }
        int sz = i - vec[x];

        frange(j, i)
        {
            cnt.pb(x);
            x = (x + x) % 10;
        }
        v1 = cnt[i - 1] - cnt[vec[x] - 1];
        while (r - l >= 3)
        {
        }
    }
}