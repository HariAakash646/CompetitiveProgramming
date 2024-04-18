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

pair<ld, ld> quad(int a, int b, lli c)
{
    ld d = ((b * b) / 16) - (c);
    // cout << d << "\n";
    if (d >= 0)
    {
        ld o1 = (-b + 4 * sqrt(d)) / (2 * a);
        ld o2 = (-b - 4 * sqrt(d)) / (2 * a);
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
        lli n;
        sclld(n);
        auto p1 = quad(4, 4, -n + 1);
        auto p2 = quad(4, 0, -n);
        ld o1, o2;
        if (p1.f >= 0)
        {
            o1 = ceil(p1.f);
        }
        else
            o1 = ceil(p1.s);
        if (p2.f >= 0)
        {
            o2 = ceil(p2.f);
        }
        else
            o2 = ceil(p2.s);
        // cout << p1.f << " " << p1.s << " " << p2.f << " " << p2.s;

        if (o2 <= o1)
        {
            cout << lli(2 * (o2 - 1) + 1) << "\n";
        }
        else
        {
            cout << lli(2 * (o1 - 1) + 2) << "\n";
        }
    }
}