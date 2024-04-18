#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

typedef tree<
    int,
    null_type,
    greater_equal<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

int main()
{
    int n, k, q;
    scd(n);
    scd(k);
    scd(q);

    lli tot = 0;
    ordered_set st;

    frange(i, n) st.insert(0);
    vi vec(n + 1);

    frange(i, q)
    {
        int x;
        lli y;
        scd(x);
        sclld(y);
        auto it = st.find_by_order(k - 1);
        if (vec[x] >= *it && y <= *it)
        {
            tot -= vec[x];
            st.erase(st.find_by_order(st.order_of_key(vec[x])));
            st.insert(y);
            tot += *st.find_by_order(k - 1);
        }
        else if (vec[x] >= *it)
        {
            tot -= vec[x];
            tot += y;
            st.erase(st.find_by_order(st.order_of_key(vec[x])));
            st.insert(y);
        }
        else if (vec[x] < *it && y > *it)
        {
            tot -= *it;
            tot += y;
            st.erase(st.find_by_order(st.order_of_key(vec[x])));
            st.insert(y);
        }
        else if (vec[x] < *it)
        {
            st.erase(st.find_by_order(st.order_of_key(vec[x])));
            st.insert(y);
        }
        vec[x] = y;
        printf("%lld\n", tot);
    }
    // for (auto e : st)
    //     printf("%d ", e);
    // printf("\n");
    // st.erase(st.find_by_order(st.order_of_key(10)));
    // for (auto e : st)
    //     printf("%d ", e);
}