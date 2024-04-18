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

int k, n, m, o;
vvi graph;

vector<vvi> lift;

vi binlift(int x, int c) {
    vi out(k, 1e9);
    out[x%k] = 0;
    frange(i, 20) {
        if(c & (1<<i)) {
            
            vi nex(k, 1e9);
            frange(l, k) {
                frange(r, k) {
                    if((x/k)*k+r< n)
                        nex[l] = min(nex[l], out[r] + lift[i][(x/k)*k+r][l]);
                    
                }
            }
            x = x + (i<<i) * k;
            out = nex;
        }
    }
    return out;
}

int main() {
    // usaco();
    scd(k);
    scd(n);
    scd(m);
    scd(o);
    graph = vvi(n+1, vi(k, 1e9));

    frange(i, m) {
        int a, b;
        scd(a);
        scd(b);
        int t;
        scd(t);
        graph[a][b%k] = t;
    }

    lift = vector<vvi>(20, vvi(n+1, vi(k, 1e9)));

    forr(i, 0, n+1) {
        lift[0][i] = graph[i];
    }

    forr(i, 1, 20) {
        forr(j, 0, n) {
            frange(l, k) {
                frange(r, k) {
                    if((j/k + (1<<(i-1)))*k + r< n)
                        lift[i][j][l] = min(lift[i][j][l], lift[i-1][j][r] + lift[i-1][(j/k + (1<<(i-1)))*k + r][l]);
                }
            }
        }
    }

    frange(i, o) {
        int a, b;
        scd(a);
        scd(b);
        if(b < a) {
            printf("-1\n");
            continue;
        }
        vi out = binlift(a, b/k - a/k);
        int mi = out[b%k];
        if(mi < 1e9) printf("%d\n", mi);
        else printf("-1\n");
    }

}