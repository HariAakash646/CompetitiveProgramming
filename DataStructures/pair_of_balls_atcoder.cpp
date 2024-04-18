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

set<pii> st;
vector<queue<int>> vec;

void rec(int id)
{
    if (vec[id].size() == 0)
        return;
    int x = vec[id].front();
    vec[id].pop();
    auto itr = st.lower_bound({x, 0});
    if (itr != st.end() && (*itr).f == x)
    {
        rec(id);
        rec((*itr).s);
    }
    else
    {
        st.insert({x, id});
    }
}

int main()
{
    int n, m;
    scd(n);
    scd(m);

    vec = vector<queue<int>>(m);
    frange(i, m)
    {
        int k;
        scd(k);
        frange(j, k)
        {
            int a;
            scd(a);
            vec[i].push(a);
        }
    }
    frange(i, m)
    {
        rec(i);
    }
    for (auto e : vec)
    {
        if (e.size())
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
}