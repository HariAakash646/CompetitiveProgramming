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
    int n, k;
    scd(n);
    scd(k);
    vll vec(n);
    frange(i, n) sclld(vec[i]);
    multiset<lli> st1, st2;
    int s1 = (k + 1) / 2;
    int s2 = k / 2;
    vi ve(k);
    frange(i, k) ve[i] = vec[i];
    sort(all(ve));
    frange(i, s1) st1.insert(ve[i]);
    frange(i, s2) st2.insert(ve[s1 + i]);

    lli v1 = 0;
    lli v2 = 0;
    for (auto e : st1)
        v1 += e;
    for (auto e : st2)
        v2 += e;
    lli tot = (s1 * *prev(st1.end()) - v1) + (v2 - s2 * *prev(st1.end()));
    printf("%lld ", tot);
    forr(i, 1, n - k + 1)
    {
        auto it1 = st1.find(vec[i - 1]);
        auto it2 = st2.find(vec[i - 1]);
        if (it1 != st1.end())
        {
            v1 -= vec[i - 1];
            st1.erase(it1);
        }
        else
        {
            v2 -= vec[i - 1];
            st2.erase(it2);
        }
        if (st2.size() && *st2.begin() <= vec[i + k - 1])
        {
            v2 += vec[i + k - 1];
            st2.insert(vec[i + k - 1]);
        }
        else
        {
            v1 += vec[i + k - 1];
            st1.insert(vec[i + k - 1]);
        }
        if (st1.size() > s1)
        {
            auto it = prev(st1.end());
            v1 -= *it;
            v2 += *it;
            st2.insert(*it);
            st1.erase(it);
        }
        if (st2.size() > s2)
        {
            auto it = st2.begin();
            v2 -= *it;
            v1 += *it;
            st1.insert(*it);
            st2.erase(it);
        }
        tot = (s1 * *prev(st1.end()) - v1) + (v2 - s2 * *prev(st1.end()));
        printf("%lld ", tot);
    }
}