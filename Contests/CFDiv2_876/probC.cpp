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

vi vec;
vi out;

void rec(int id, int flip)
{
    // printf("%d ", id);
    if (vec[id] ^ flip == 0)
    {
        if (id - 1 >= 0 && vec[id - 1] ^ flip == 1)
        {
            rec(id - 1, !flip);
            out.pb(id);
        }
        else
        {
            out.pb(0);
            if (id - 1 >= 0)
                rec(id - 1, flip);
        }
    }
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        out = {};
        int n;
        scd(n);
        vec = vi(n);
        frange(i, n) scd(vec[i]);
        if (vec[n - 1])
            printf("NO\n");
        else
        {
            printf("YES\n");
            rec(n - 1, 0);
            for (auto e : out)
                printf("%d ", e);
            printf("\n");
        }
    }
}