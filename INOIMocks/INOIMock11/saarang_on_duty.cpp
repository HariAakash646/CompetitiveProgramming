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
#define MP make_pair
#define pb push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vector<lli> disset, vec, sze;
vector<lli> sum;
multiset<lli> sumset;

int findf(int n)
{
    if (disset[n] != n)
    {
        disset[n] = findf(disset[n]);
    }
    return disset[n];
}

bool unionf(int n1, int n2)
{
    int f1 = findf(n1);
    int f2 = findf(n2);
    if (f1 == f2)
    {
        return false;
    }
    if (sze[f2] > sze[f1])
        swap(f1, f2);
    sze[f1] += sze[f2];
    disset[f2] = f1;
    sumset.erase(sumset.find(sum[f1]));
    sumset.erase(sumset.find(sum[f2]));
    sum[f1] += sum[f2];
    // sum[f2] = sum[f1];
    sumset.insert(sum[f1]);
    return true;
}

int main()
{
    int n, m, q;
    scd(n);
    scd(m);
    scd(q);
    disset = vector<lli>(n + 1);
    vec = vector<lli>(n + 1);
    sze = vector<lli>(n + 1, 1);
    sum = vector<lli>(n + 1);
    forr(i, 1, n + 1)
    {
        sclld(vec[i]);
        disset[i] = i;
        sum[i] = vec[i];
        sumset.insert(vec[i]);
    }

    frange(i, m)
    {
        int a, b;
        scd(a);
        scd(b);
        bool out = unionf(a, b);
    }
    vi val(all(sumset));
    vi pref(sumset.size() + 1);
    lli tot = 0;
    forr(i, 1, pref.size())
    {
        pref[i] = pref[i - 1] + val[i - 1];
        tot += pref[i];
    }
    // int tot = 0;
    // for (auto e : sumset)
    // {
    //     tot += (k * e);
    //     k--;
    // }
    // for (auto e : disset)
    // {
    //     printf("%d ", e);
    // }
    printf("\n");
    frange(i, q)
    {
        int a, b;
        scd(a);
        scd(b);
        int fa = findf(a);
        int fb = findf(b);
        if (fa == fb)
        {
            printf("%lld\n", tot);
            continue;
        }
        lli s1 = sum[fa];
        lli s2 = sum[fb];
        int idx1 = (upper_bound(all(val), s1) - val.begin()) - 1;
        int idx2 = (upper_bound(all(val), s2) - val.begin()) - 1;
        if (idx2 > idx1)
            swap(idx1, idx2);
        int tmp_tot = tot;
        int idx3 = (upper_bound(all(val), s1 + s2) - val.begin());
        tot -= pref[idx1] - pref[idx2];
        tot -= 2 * (pref[idx3] - pref[idx1]);

        tot -= pref[pref.size() - 1] - pref[idx3];
        tot += (pref.size() - idx3) * (s1 + s2);

        printf("%lld\n", tot);
        tot = tmp_tot;
    }
}