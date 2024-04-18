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
typedef long double ld;

void usaco()
{
    freopen("input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

vector<mseti> vl;
vb vis;
vi nex;

bool dfs(int x, int st) {
    if(vis[x]) return false;
    vis[x] = true;
    if(vl[nex[x]].size()) {
        if(vl[nex[x]].find(st) != vl[nex[x]].end()) {
            vl[nex[x]].erase(st);
            return true;
        }
        int v = *vl[nex[x]].begin();
        vl[nex[x]].erase(vl[nex[x]].begin());
        bool out = dfs(v, st);
        return out;
    }
    else return false;

}

int main() {
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n;
        scd(n);
        vll vec(n);
        lli tot = 0;
        frange(i, n) {
            sclld(vec[i]);
            tot += vec[i];
        }
        if(tot % n) {
            printf("NO\n");
        }
        else {
            lli v = tot / n;
            vii val(n);
            bool done = true;
            int d = 0;
            vi cnt1(31), cnt2(31);
            frange(i, n) {
                lli x = v - vec[i];
                bool over = true;
                
                frange(j, 31) {
                    frange(k, 31) {
                        if((1<<j) - (1<<k) == x) {
                            val[i] = {j, k};
                            cnt1[j]++;
                            cnt2[k]++;
                            over = false;
                            if(j == k) {
                                val[i] = {-1, -1};
                                d++;
                            }
                            break;
                        }
                    }
                }
                if(over) {
                    done = false;
                    break;
                }
            }
            if(!done) {
                printf("NO\n");
                continue;
            }

            // nex = vi(n);
            // vis = vb(n);
            // vl = vector<mseti>(20);

            // frange(i, n) {
            //     if(val[i].f != -1) {
            //         nex[i] = val[i].s;
            //         vl[val[i].f].insert(i);
            //     }
            // }

            // frange(i, n) {
            //     if(!vis[i] && val[i].f != -1) {
            //         done = done && dfs(i, i);
            //     }
            // }
            frange(i, 31) {
                if(cnt1[i] != cnt2[i]) done = false;
            }
            // frange(i, n) {
            //     if(vl[i].size()) done = false;
            // }
            if(done) printf("YES\n");
            else printf("NO\n");
        }
    }
}