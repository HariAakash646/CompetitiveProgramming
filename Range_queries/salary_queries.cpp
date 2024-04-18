#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

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

typedef tree<
    pii,
    null_type,
    less<pii>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

int main()
{
    int n, q;
    scd(n);
    scd(q);
    vi vec(n);
    ordered_set st;
    frange(i, n)
    {
        scd(vec[i]);
        st.insert({vec[i], i});
    }
    frange(i, q)
    {
        char a;
        int k, x;
        cin >> a >> k >> x;
        if (a == '?')
        {
            printf("%d\n", st.order_of_key({x + 1, 0}) - st.order_of_key({k, 0}));
        }
        else
        {
            k--;
            st.erase({vec[k], k});
            st.insert({x, k});
            vec[k] = x;
        }
    }
}