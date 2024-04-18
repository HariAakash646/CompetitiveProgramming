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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

int main()
{
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);

    int n;
    scd(n);
    vector<lli> vec(n + 1, 0);
    vector<lli> sum_arr(n + 1, 0);
    vector<vector<int>> rem(7);
    rem[0].PB(0);
    forr(i, 1, n + 1, 1)
    {
        sclld(vec[i]);
        sum_arr[i] = vec[i] + sum_arr[i - 1];
        rem[(sum_arr[i] % 7)].PB(i);
    }
    int m = 0;
    for (vi v : rem)
    {
        if (v.empty())
            continue;
        m = max(m, *(v.end() - 1) - *v.begin());
    }
    printf("%d", m);
}