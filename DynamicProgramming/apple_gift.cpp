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

vi dp;
int rec(int w, vi &vec)
{
    if (w == 0)
        return 1;
    if (w < 0)
        return 0;
    if (dp[w / 100] != -1)
        return dp[w / 100];
    if (vec.empty())
        return 0;
    int a = 0;
    int b = 0;
    vi copy_vec(vec.size() - 1);
    if (vec[0] == 100)
    {
        copy(vec.begin() + 1, vec.end(), copy_vec.begin());
        a = rec(w - 100, copy_vec);
    }
    if (vec[vec.end() - vec.begin() - 1] == 200)
    {
        copy(vec.begin(), vec.end() - 1, copy_vec.begin());
        b = rec(w - 200, copy_vec);
    }
    dp[w / 100] = max(a, b);
    return dp[w / 100];
}

int main()
{
    int n;
    scd(n);
    vector<int> apples(n);
    frange(i, n)
    {
        scd(apples[i]);
    }
    int tw = accumulate(apples.begin(), apples.end(), 0) / 100;
    if (tw % 2 != 0)
    {
        cout << "NO";
        return 0;
    }
    dp = vi(tw / 2 + 1, -1);
    dp[0] = 1;
    sort(apples.begin(), apples.end());
    int ans = rec(tw * 100 / 2, apples);
    if (ans)
        printf("YES");
    else
        printf("NO");
    return 0;
}