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

int mab(int x, int y) {
    if(__builtin_popcount(x) >= __builtin_popcount(y)) return x;
    else return y;
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);
    vector<seti> graph(n+1);
    forr(i, 1, n+1) {
        forr(j, 1, n+1) {
            if(i != j) graph[i].insert(j);
        }
    }

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        a++;
        b++;
        graph[a].erase(b);
        graph[b].erase(a);
    }

    int n1 = (n+1)/2;
    int n2 = n/2;

    vb dp11(1<<n1), dp21(1<<n2);
    vi dp12(1<<n1), dp22(1<<n2);

    dp11[0] = true;
    dp12[0] = 0;

    forr(i, 1, 1<<n1) {
        frange(j, n1) {
            if(i & (1<<j)) {
                if(!dp11[i ^ (1<<j)]) break;
                int v = 0;
                v = v | (1<<j);
                for(auto e : graph[j+1]) {
                    if(e <= n1)
                    v = v | (1<<(e-1));
                }
                // printf("%d %d\n", v, i);
                if((v & i) == i) {
                    dp11[i] = true;
                }
                break;
            }
        }
        if(dp11[i]) {
            dp12[i] = i;
        }
        frange(j, n1) {
            if(i & (1<<j)) {
                dp12[i] = mab(dp12[i], dp12[i^(1<<j)]);
            }
        }
    }

    // forr(i, 1, 1<<n1) {
    //     if(dp11[i]) {
    //         frange(j, n1) {
    //             if(i & (1<<j)) printf("%d ", j);
    //         }
    //         printf("\n");
    //     }
    // }

    dp21[0] = true;
    forr(i, 1, 1<<n2) {
        frange(j, n2) {
            if(i & (1<<j)) {
                if(!dp21[i ^ (1<<j)]) break;
                int v = 0;
                v = v | (1<<j);
                for(auto e : graph[n1+j+1]) {
                    if(e >= n1+1)
                    v = v | (1<<(e-1-n1));
                }
                if((v & i) == i) {
                    dp21[i] = true;
                }
                break;
            }
        }
        if(dp21[i]) {
            dp22[i] = i;
        }
        frange(j, n2) {
            if(i & (1<<j)) {
                dp22[i] = mab(dp22[i], dp22[i^(1<<j)]);
            }
        }
    }

    pair<int, pii> ma = mp(0, mp(0, 0));

    frange(i, 1<<n1) {
        if(dp11[i]) {
            vi cnt(n2);
            frange(j, n1) {
                if(i & (1<<j)) {
                    for(auto e : graph[j+1]) {
                        if(e >= n1+1)
                            cnt[e-n1-1]++;
                    }
                }
            }
            int v = 0;
            int c = __builtin_popcount(i);
            frange(j,n2) {
                if(cnt[j] == c) v = v | (1<<j);
            }
            // printf("%d\n", v);
            ma = max(ma, mp(c + __builtin_popcount(dp22[v]), mp(i, dp22[v])));
        }
    }
    printf("%d\n", ma.f);
    frange(i, n1) {
        if(ma.s.f & (1<<i)) printf("%d ", i);
    }
    frange(j, n2) {
        if(ma.s.s & (1<<j)) printf("%d ", n1+j);
    }

}