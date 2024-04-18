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

int main()
{
    int n, k;
    scd(n);
    scd(k);
    vi vec(n);
    vi v2(n);
    frange(i, n)
    {
        scd(vec[i]);
        v2[i] = vec[i];
    }
    sort(all(v2));
    frange(i, k)
    {
        int id = i;
        vi tm;
        while (id < n)
        {
            tm.pb(vec[id]);
            id += k;
        }
        sort(all(tm));
        frange(j, tm.size())
        {
            vec[j * k + i] = tm[j];
        }
    }

    if (v2 == vec)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
}