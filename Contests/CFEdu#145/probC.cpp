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

pair<ld, ld> quad(int a, int b, int c)
{
    ld d = ((b * b)) - (4 * a * c);
    // cout << d << "\n";
    if (d >= 0)
    {
        ld o1 = (-b + sqrt(d)) / (2 * a);
        ld o2 = (-b - sqrt(d)) / (2 * a);
        return {o1, o2};
    }
    return {-1, -1};
}

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n, k;
        scd(n);
        scd(k);
        auto p = quad(1, 1, 2 * k - n * n - n);
        ld o = n - max(p.f, p.s);
        vi vec(n, -1);
        frange(i, int(o))
        {
            vec[i] = 999;
        }
        int tot = 0;
        int curr = n;
        frange(i, int(o))
        {
            tot += curr;
            curr--;
        }
        if (k - tot > 0)
        {

            vec[int(o)] = 999;
            vec[int(o) + k - tot] = -1000;
        }
        for (auto e : vec)
        {
            printf("%d ", e);
        }
        printf("\n");
    }
}