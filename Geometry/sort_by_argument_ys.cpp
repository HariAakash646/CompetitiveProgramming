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

// Geometry
typedef complex<long double> point;
#define x real()
#define y imag()

int main()
{
    int n;
    scd(n);
    vector<pair<long double, pair<lli, lli>>> vec(n);
    frange(i, n)
    {
        long double a, b;
        cin >> a >> b;
        vec[i].s.f = a;
        vec[i].s.s = b;
        vec[i].f = atan2l(b, a);
        // cout << vec[i].f << " ";
    }
    sort(all(vec));
    for (auto p : vec)
    {
        printf("%d %d\n", p.s.f, p.s.s);
    }
}