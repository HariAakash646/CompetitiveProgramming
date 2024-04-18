#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

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
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
    int n;
    scd(n);
    vi vec(n);
    Tree<pii> st1;
    Tree<pii> st2;
    frange(i, n)
    {
        scd(vec[i]);
    }
    vii cnt(n);
    frange(i, n)
    {
        cnt[i].f = i - st1.order_of_key({vec[i], i});
        st1.insert({vec[i], i});
    }
    frange(i, n)
    {
        cnt[n - (i + 1)].s = i - st2.order_of_key({vec[n - (i + 1)], i});
        st2.insert({vec[n - (i + 1)], i});
    }
    int c = 0;
    for (auto p : cnt)
    {
        int a = p.f;
        int b = p.s;
        if (a > b)
            swap(a, b);
        if (b > 2 * a)
            c++;
    }
    printf("%d", c);
}