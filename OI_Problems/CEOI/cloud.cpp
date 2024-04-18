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

struct Data {
    int c, fv, v;

    bool operator<(Data other) {
        return fv > other.fv;
    }
};

int main() {
    // usaco();
    int n;
    scd(n);

    vector<Data> comp(n);

    frange(i, n) {
        scd(comp[i].c);
        scd(comp[i].fv);
        scd(comp[i].v);
    }
    sort(all(comp));

    int m;
    scd(m);
    vector<Data> cust(m);

    frange(i, m) {
        scd(cust[i].c);
        scd(cust[i].fv);
        scd(cust[i].v);
    }

    sort(all(cust));

    vector<lli> dp(n*50+1, -1e18);
    dp[0] = 0;

    int id = 0;

    frange(i, m) {
        int tid = id;
        // vector<lli> tmp = dp;
        forr(j, tid, n) {
            if(comp[j].fv >= cust[i].fv) {
                for(int k=50*n; k>=comp[j].c; k--) {
                    dp[k] = max(dp[k], dp[k-comp[j].c] - comp[j].v);
                    // if(k <50*n)
                    //     dp[k] = max(dp[k], dp[k+1]);
                }
                id = j+1;
            } 
            else break;
        }
        vector<lli> tmp(50*n+1);
        for(int j=50*n; j>=0; j--) {
            tmp[j] = dp[j];
            // if(j < 50*n) tmp[j] = max(tmp[j], tmp[j+1]);
            if(j + cust[i].c <= 50*n) {
                tmp[j] = max(tmp[j], dp[j+cust[i].c] + cust[i].v);
            }
        }
        dp = tmp;
        // frange(i, n*20+1) printf("%lld ", dp[i]);
        // printf("\n");
    }
    printf("%lld", *max_element(all(dp)));
}