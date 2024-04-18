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
#define MP make_pair
#define pb push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int w, d, h, a, b, f, g;
        scd(w);
        scd(d);
        scd(h);
        scd(a);
        scd(b);
        scd(f);
        scd(g);
        int o1, o2, o3, o4;
        o1 = a + f + abs(b - g);
        o2 = (w - a) + (w - f) + abs(b - g);
        o3 = b + g + abs(a - f);
        o4 = (d - b) + (d - g) + abs(a - f);
        printf("%d\n", min({o1, o2, o3, o4}) + h);
    }
}