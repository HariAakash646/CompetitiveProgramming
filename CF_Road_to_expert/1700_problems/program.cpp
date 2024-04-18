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

struct dat
{
    int ma = 0;
    int mi = 0;
    int sum = 0;
};

int main()
{
    int t;
    scd(t);
    frange(_, t)
    {
        int n, m;
        scd(n);
        scd(m);
        vi vec(n + 1, 1);
        vec[0] = 0;
        string seq;
        cin >> seq;
        frange(i, n)
        {
            if (seq[i] == '-')
                vec[i + 1] = -vec[i + 1];
        }
        vector<dat> pref(n + 1);
        forr(i, 1, n + 1)
        {
            pref[i].sum = pref[i - 1].sum + vec[i];
            pref[i].ma = max(pref[i].sum, pref[i - 1].ma);
            pref[i].mi = min(pref[i].sum, pref[i - 1].mi);
        }
        vector<dat> suf(n + 2);
        for (int i = n; i >= 1; i--)
        {
            suf[i].sum = suf[i + 1].sum + vec[i];
            suf[i].ma = max(suf[i].sum, suf[i + 1].ma);
            suf[i].mi = min(suf[i].sum, suf[i + 1].mi);
        }
        frange(i, m)
        {
            int l, r;
            scd(l);
            scd(r);
            int ma = max(pref[l - 1].ma, pref[l - 1].sum + suf[r + 1].sum - suf[r + 1].mi);
            int mi = min(pref[l - 1].mi, pref[l - 1].sum + suf[r + 1].sum - suf[r + 1].ma);
            printf("%d\n", ma - mi + 1);
        }
    }
}