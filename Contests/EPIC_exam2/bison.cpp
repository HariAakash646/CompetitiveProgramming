#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long long int lli;
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

ld area(vector<pair<lli, lli>> vec)
{
    int n = vec.size();
    lli ar = 0;
    frange(i, n - 1)
    {
        ar += vec[i].f * vec[i + 1].s;
    }
    ar += vec[n - 1].f * vec[0].s;
    for (int i = n - 1; i >= 1; i--)
    {
        ar -= vec[i].f * vec[i - 1].s;
    }
    ar -= vec[0].f * vec[n - 1].s;
    return ld(abs(ar)) / 2.0;
}

int main()
{
    int n;
    scd(n);

    vector<pair<lli, lli>> vec(n);
    frange(i, n)
    {
        sclld(vec[i].f);
        sclld(vec[i].s);
    }
    ld mi = 1e18;
    frange(i, n)
    {
        forr(j, 0, n)
        {
            vector<pair<lli, lli>> v1, v2;
            forr(k, i, j + 1)
            {
                v1.pb(vec[k]);
            }
            forr(k, j, n) v2.pb(vec[k]);
            forr(k, 0, i + 1) v2.pb(vec[k]);
            if (v1.size() >= 3 && v2.size() >= 3)
                mi = min(mi, abs(area(v1) - area(v2)));
        }
    }
    cout << fixed << setprecision(10) << mi;
}