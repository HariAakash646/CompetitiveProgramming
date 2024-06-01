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

const lli mod = 998244353;

vii tree;
vi val;

lli inv(lli a) {
  return a <= 1 ? a : mod - (mod/a) * inv(mod % a) % mod;
}

vi vec;

void dfs(int x) {
    if(x==-1) return;
    dfs(tree[x].f);
    vec.pb(val[x]);
    dfs(tree[x].s);
}   

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, c;
        scd(n);
        scd(c);
        tree = vii(n+1);
        val = vi(n+1);
        forr(i, 1, n+1) {
            scd(tree[i].f);
            scd(tree[i].s);
            scd(val[i]);
        } 

        vec = {};
        dfs(1);
        vec.pb(c);

        int curr = 0;
        lli pre = 1;
        lli tot = 1;
        frange(i, n+1) {
            if(vec[i] == -1) curr++;
            else {
                lli v = curr + (vec[i] - pre);
                frange(j, curr) {
                    tot *= v;
                    tot %= mod;
                    v--;
                }
                lli m = 1;
                forr(i, 1, curr+1) {
                    m*=i;
                    m%=mod;
                }
                tot = (tot * inv(m)) % mod;
                curr = 0;
                pre = vec[i];
            }
        }
        printf("%lld\n", tot);
    }
}