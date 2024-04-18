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

vi cnt;
vvi grid;
const lli mod = 1e9 + 7;

template <class T>
struct BIT
{
    int size;
    vector<T> bit;
    vector<T> vec;

    BIT(int n) : size(n), bit(n + 1), vec(n + 1) {}

    int lsb(int x)
    {
        return x & (-x);
    }

    void set(int id, T v)
    {
        add(id, (v - vec[id]+mod)%mod);
    }

    void add(int id, T v)
    {
        if (id == 0)
            return;
        vec[id] += v;
        vec[id] %= mod;
        while (id <= size)
        {
            bit[id] += v;
            bit[id] %= mod;
            id += lsb(id);
        }
    }

    T query(int id)
    {
        T tot = 0;
        if (id == 0)
            return tot;
        while (id >= 1)
        {
            tot += bit[id];
            tot %= mod;
            id -= lsb(id);
        }
        return tot;
    }
};

int main() {
    // usaco();
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
    int r, c, k;
    scd(r);
    scd(c);
    scd(k);

    grid = vvi(r+1, vi(c+1));
    cnt = vi(k+1);
    vector<vii> pos(k+1);

    forr(i, 1, r+1) {
        forr(j, 1, c+1) {
            scd(grid[i][j]);
            cnt[grid[i][j]]++;
            pos[grid[i][j]].pb(mp(i, j));
        }
    }

    int sq = sqrt(r*c);

    BIT<lli> bit(c+1);

    vi big(k+1, -1);
    vector<BIT<lli>> col;

    forr(i, 1, k+1) {
        if(cnt[i] >= sq) {
            big[i] = col.size();
            col.pb(BIT<lli>(c+1));
        }
    }
    vector<vll> tot(r+1, vll(c+1));
    bit.add(1, 1);
    tot[1][1]++;
    if(big[grid[1][1]] != -1) {
        col[big[grid[1][1]]].add(1, 1);
    }

    forr(i, 2, r+1) {
        forr(j, 2, c+1) {
            tot[i][j] = bit.query(j-1);
            if(big[grid[i][j]] != -1) {
                tot[i][j] -= col[big[grid[i][j]]].query(j-1);
                tot[i][j] += mod;
                tot[i][j] %= mod;
            }
            else {
                for(auto p : pos[grid[i][j]]) {
                    if(p.f < i && p.s < j) {
                        tot[i][j] -= tot[p.f][p.s];
                        tot[i][j] += mod;
                        tot[i][j] %= mod;
                    }
                }
            }
        }
        forr(j, 2, c+1) {
            bit.add(j, tot[i][j]);
            if(big[grid[i][j]] != -1) {
                col[big[grid[i][j]]].add(j, tot[i][j]);
            }
        }
    }

    printf("%lld", tot[r][c]);




}