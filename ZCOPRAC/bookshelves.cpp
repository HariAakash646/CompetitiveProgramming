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
    vi v1(n);
    vi v2(n);
    frange(i, n) scd(v1[i]);
    frange(i, n) scd(v2[i]);

    // if (*max_element(all(v2)) > *max_element(all(v1)))
    //     swap(v1, v2);
    mseti s1, s2;
    for (auto e : v1)
        s1.insert(e);
    for (auto e : v2)
        s2.insert(e);
    int ans = 1e9;
    frange(_, k + 1)
    {
        ans = min(ans, *prev(s1.end()) + *prev(s2.end()));
        int v1 = *s1.begin();
        int v2 = *prev(s2.end());

        s1.erase(s1.begin());
        s2.erase(prev(s2.end()));
        s1.insert(v2);
        s2.insert(v1);
    }
    s1 = {};
    s2 = {};
    for (auto e : v2)
        s1.insert(e);
    for (auto e : v1)
        s2.insert(e);
    frange(_, k + 1)
    {
        ans = min(ans, *prev(s1.end()) + *prev(s2.end()));
        int v1 = *s1.begin();
        int v2 = *prev(s2.end());

        s1.erase(s1.begin());
        s2.erase(prev(s2.end()));
        s1.insert(v2);
        s2.insert(v1);
    }

    printf("%d", ans);
}