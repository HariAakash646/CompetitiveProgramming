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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<lli> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

int n;
vi vec;
vi idx;
seti st;
vi out;

void rec(int i1, int k)
{
    if (i1 >= n)
        return;
    forr(i, 1, n + 1)
    {
        if (st.find(i) != st.end())
            continue;
        int x;
        if (vec[i1] == i)
        {
            x = ((n - i1) * (n - i1 + 1)) / 2;
            if (k - x == 0)
            {
                reverse(vec.begin() + i1, vec.end());
                return;
            }
        }
        else
        {
            x = 1;
            if (k - x == 0)
            {
                reverse(vec.begin() + i1, vec.begin() + idx[i] + 1);
                return;
            }
        }
        k -= x;
        if (k < 0)
        {
            k += x;
            st.insert(vec[i1]);
            // out.pb(vec[i1]);
            rec(i1 + 1, k);
            return;
        }
    }
}

int main()
{
    int k;
    scd(n);
    scd(k);

    vec = vi(n);
    idx = vi(n + 1);
    frange(i, n)
    {
        scd(vec[i]);
        idx[vec[i]] = i;
    }

    rec(0, k);
    for (auto e : vec)
        printf("%d ", e);
}