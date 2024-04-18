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
    // freopen("disrupt.in", "r", stdin);
    // freopen("disrupt.out", "w", stdout);
}

int main() {
    // usaco();
    int n, m, q;
    scd(n);
    scd(m);
    scd(q);

    vvi graph(n+1);
    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        graph[b].pb(a);
    }

    int sq = 320;

    vector<vii> topo(n+1, vii(sq+1, mp(-1e9, -1)));
    forr(i, 1, n+1) {
        vi cnt(graph[i].size());
        // printf("%d\n", i);
        frange(j, sq+1) {
            int ma = -1;
            int mid = -1;
            int me = -1;
            frange(k, graph[i].size()) {
                int e = graph[i][k];
                // printf("%d\n", e);
                if(topo[e][cnt[k]].f + 1 > 0 && topo[e][cnt[k]].f + 1 > ma) {
                    ma = topo[e][cnt[k]].f + 1;
                    mid = topo[e][cnt[k]].s;
                    me = k;
                }
            }
            if(mid == -1) {
                topo[i][j] = mp(0, i);
                // printf("%d %d %d %d\n", i, j, 0, i);
                break;
            }
            else {
                cnt[me]++;
                topo[i][j] = mp(ma, mid);
                // printf("%d %d %d %d\n", i, j, ma, mid);
            }
        }
    }


    vb busy(n+1);
    frange(_, q) {
        int t, y;
        scd(t);
        scd(y);

        vi vec;
        frange(i, y) {
            int a;
            scd(a);
            vec.pb(a);
            busy[a] = true;
        }

        if(y >= sq-1) {
            vi topo2(n+1, -1e9);
            forr(i, 1, n+1) {
                if(!busy[i]) {
                    topo2[i] = 0;
                }
                for(auto e : graph[i]) {
                    topo2[i] = max(topo2[e]+1, topo2[i]);
                }
            }
            if(topo2[t] >= 0) printf("%d\n", topo2[t]);
            else printf("-1\n");
        }
        else {
            frange(i, sq+2) {
                if(i==sq+1 || topo[t][i].s == -1) {
                    printf("%d\n", -1);
                    break;
                }
                else {
                    if(!busy[topo[t][i].s]) {
                        printf("%d\n", topo[t][i].f);
                        break;
                    }
                }
            }
        }
        for(auto e : vec) busy[e] = false;
    }
}