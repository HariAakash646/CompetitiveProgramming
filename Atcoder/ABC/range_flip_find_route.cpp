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
typedef pair<int, pii> piii;

int main()
{
    int h, w;
    cin >> h >> w;
    vvi vec(h + 1, vi(w + 1));
    frange(i, h)
    {
        string row;
        cin >> row;
        frange(j, w)
        {
            if (row[j] == '#')
                vec[i + 1][j + 1] = 1;
        }
    }
    // vector<vector<vector<piii>>> graph(h, vector<vector<piii>>(w));
    // frange(i, h) {
    //     frange(j, w) {
    //         if(i + 1 < h) {
    //             if(vec[i+1][j])
    //             graph[i][j].pb(mp(mp(i+1, j), ))
    //         }
    //     }
    // }
    vvi dp(h + 1, vi(w + 1));
    forr(i, 1, h + 1)
    {
        forr(j, 1, w + 1)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + vec[i][j];
        }
    }
    printf("%d", dp[h][w]);
}