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

int main()
{
    int n;
    scd(n);
    vi vec(n);
    int mi = 1e9;
    frange(i, n)
    {
        scd(vec[i]);
        mi = min(mi, vec[i]);
    }
    mseti st;
    lli c = 0;
    frange(i, n)
    {
        c += vec[i] / mi - 1;
        vec[i] = mi + vec[i] % mi;
        st.insert(vec[i]);
    }

    while (*st.begin() != *prev(st.end()))
    {
        int x = *prev(st.end());
        int e = *st.begin();
        st.erase(prev(st.end()));
        st.insert(x - e);
        c++;
    }
    printf("%lld", c);
}