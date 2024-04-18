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

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

bool cmp(bitset<101> x, bitset<101> y) {
    bool out = false;
    frange(i, 101) {
        if(x[i] < y[i]) {
            out = true;
            break;
        }
        if(y[i] < x[i]) {
            out = false;
            break;
        }
    }
    return out;
}

vi val;
vvi graph;

vector<vector<bitset<101>>> dp;

bool verify(bitset<101> bt, int v1) {
    bool valid = true;
    int v = 1;
    forr(i, v1+1, 101) {
        if(bt[i] == 0) v = 0;
        if(bt[i] != v) {
            valid = false;
        }
    }
    v = 1;
    for(int i=v1-1; i>=1; i--) {
        if(bt[i] == 0) v = 0;
        if(bt[i] != v) {
            valid = false;
        }
    }
    return valid;      
}

void dfs(int x) {
    bitset<101> tmp;
    tmp[val[x]] = 1;
    dp[x].pb(tmp);
    vector<bitset<101>> glob;
    glob.pb(tmp);
    for(auto e : graph[x]) {
        dfs(e);
        vector<bitset<101>> curr;
        for(auto bt : dp[e]) {
            
            for(auto bt2 : glob) {
                if((bt & bt2).count()) continue;
                auto bt3 = (bt | bt2);
                curr.pb(bt3);
            }
        }
        dp[e] = {};
        for(auto bt : curr) {
            glob.pb(bt);
            if(verify(bt, val[x])) dp[x].pb(bt);
        }
    }
    sort(all(dp[x]), cmp);
    dp[x].erase(unique(all(dp[x])), dp[x].end());
}

int main() {
    // usaco();
    int n;
    scd(n);

    graph = vvi(n+1);
    val = vi(n+1);

    forr(i, 1, n+1) scd(val[i]);

    frange(i, n-1) {
        int a, b;
        scd(a);
        scd(b);
        graph[a].pb(b);
    }
    dp = vector<vector<bitset<101>>>(n+1);
    dfs(1);
    // vector<bitset<101>> up, down;
    // vector<bitset<101>> out;
    
    // for(auto e : graph[1]) {
    //     vector<bitset<101>> upt, downt;
    //     for(auto bt : dp[e]) {
    //         bool u = false;
    //         bool d = false;
    //         bool valid = true;
    //         int v = 1;
    //         forr(i, val[1]+1, 101) {
    //             if(bt[i] == 0) v = 0;
    //             if(v) u = true;
    //             if(bt[i] != v) {
    //                 valid = false;
    //             }
    //         }
    //         v = 1;
    //         for(int i=val[1]-1; i>=1; i--) {
    //             if(bt[i] == 0) v = 0;
    //             if(v) d = true;
    //             if(bt[i] != v) {
    //                 valid = false;
    //             }
    //         }
    //         if(valid) {
    //             out.pb(bt);
    //             if(u && !d) {
    //                 for(auto bt1 : down) {
    //                     out.pb(bt | bt1);
    //                 }
    //                 upt.pb(bt);
    //             }
    //             if(d && !u) {
    //                 for(auto bt1 : up) {
    //                     out.pb(bt | bt1);
    //                 }
    //                 downt.pb(bt);
    //             }
    //         }
    //     }
    //     for(auto e : downt) down.pb(e);
    //     for(auto e : upt) up.pb(e);
    // }
    printf("%d", (int)dp[1].size());
}