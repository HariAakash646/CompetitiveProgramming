// Bugs in the indexing.
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
#define f first
#define s second
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

int main()
{
    int n;
    scd(n);
    vector<lli> vec(n + 1);
    frange(i, n)
    {
        sclld(vec[i + 1]);
    }

    vector<lli> pref(n + 1);
    vector<lli> prefrev(n + 1);
    forr(i, 1, n + 1)
    {
        pref[i] = pref[i - 1] + vec[i];
        prefrev[n - i] = vec[n - i + 1] + prefrev[n - i + 1];
    }
    if (n < 3 || pref[n] % 3 != 0)
    {
        printf("0");
        return 0;
    }
    lli div3 = pref[n] / 3;
    lli c1 = 0, c2 = 0;
    vector<lli> cnt(n + 2);
    forr(i, 1, n + 1)
    {

        cnt[n - i + 1] = (prefrev[n - i] == div3) + cnt[n - i + 2];
    }
    lli tot = 0;
    forr(i, 1, n)
    {
        if (pref[i] == div3)
        {
            tot += cnt[i + 1];
        }
    }

    printf("%lld", tot);
}