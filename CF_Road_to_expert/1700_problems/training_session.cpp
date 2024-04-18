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
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        lli n;
        sclld(n);
        vll diff(n + 1);
        vll topi(n + 1);
        vii vec(n);
        seti st;
        frange(i, n)
        {
            int a, b;
            scd(a);
            scd(b);
            topi[a]++;
            diff[b]++;
            st.insert({a, b});
            vec[i] = {a, b};
        }
        sort(all(vec));
        lli c = n;
        lli tot = 0;

        frange(i, n)
        {
            auto p = vec[i];
            tot += ((topi[p.f] - 1) * (diff[p.s] - 1));
        }
        printf("%lld\n", (n * (n - 1) * (n - 2)) / 6 - tot);
    }
}