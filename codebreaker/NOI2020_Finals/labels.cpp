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
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int main()
{
    int n;
    scd(n);
    vi vec(n);
    set<pii> st;
    vll pref(n);
    forr(i, 1, n)
    {
        int a;
        scd(a);
        vec[i] = a;
        // m[a] = i;
        pref[i] = pref[i - 1] + vec[i];
        st.insert({pref[i], i});
    }
    // for (auto p : st)
    //     printf("%d %d\n", p.f, p.s);
    vll out(n + 1);
    int id = -1;
    forr(i, 1, n)
    {

        // printf("%lld ", (n - 1) - pref[i - 1]);
        auto it = st.lower_bound({(n - 1) + pref[i - 1], 0});
        if (it != st.end() && (*it).f == (n - 1) + pref[i - 1])
        {
            out[i] = 1;
            out[(*it).s] = n;
            id = i;
            break;
        }
        // it = st.lower_bound({pref[i - 1] - (n - 1), 0});
        // if (it == st.end() && (*it).f == pref[i - 1] - (n - 1))
        // {
        //     out[i] = n;
        //     out[(*it).s] = 1;
        //     id = i;
        //     break;
        // }
    }
    if (id == -1)
    {
        printf("-1");
        return 0;
    }
    for (int i = id - 1; i >= 1; i--)
    {
        // if (out[i] && out[i + 1] - vec[i] != out[i])
        // {
        //     printf("-1");
        //     return 0;
        // }
        out[i] = out[i + 1] - vec[i];
    }
    for (int i = id + 1; i <= n; i++)
    {
        // if (out[i] && out[i - 1] + vec[i - 1] != out[i])
        // {
        //     printf("-1");
        //     return 0;
        // }
        out[i] = out[i - 1] + vec[i - 1];
    }
    forr(i, 1, n + 1)
    {
        if (!(1 <= out[i] && out[i] <= n))
        {
            printf("-1");
            return 0;
        }
    }
    forr(i, 1, n + 1) printf("%d ", out[i]);
}