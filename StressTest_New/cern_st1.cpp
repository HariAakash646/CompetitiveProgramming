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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

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
        add(id, v - vec[id]);
    }

    void add(int id, T v)
    {
        if (id == 0)
            return;
        vec[id] += v;
        while (id <= size)
        {
            bit[id] += v;
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
            id -= lsb(id);
        }
        return tot;
    }
};

inline int readInt() {
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9'){
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar_unlocked();
    }
    return x;
}


int main() {
    // usaco();
    fastio();
    int n, q;
    cin >> n >> q;

    vi vec(n+1);
    forr(i, 1, n+1) cin >> vec[i];
    vi cnt(n+1);
    vi out(q);
    vector<pair<pii, int>> quer;
    frange(j, q) {
        int l, r;
        cin >> l >> r;
        
        quer.pb(mp(mp(r, l), j));
    }
    sort(all(quer));
    int en = 0;
    vector<BIT<int>> bit(11, BIT<int>(n));
    for(auto p : quer) {
        int l = p.f.s;
        int r = p.f.f;
        while(en < r) {
            en++;
            bit[vec[en]].set(en, 1);
        }
        int len = (r-l+1);
        int ma = 0;
        int c = 0, c2=0;
        forr(i, 1, 11) {
            int v = bit[i].query(r) - bit[i].query(l-1);
            ma = max(ma, v);
            if(v) c++;
            if(v >= 2) c2++;
        }
        
        if(ma > len/2) {
            out[p.s] = 1;
        }
        else if(len % 2 == 0 && ma == len / 2) {
            if(c == 2)
                out[p.s] = 0;
            else out[p.s] = 1;
        }
        else if(len % 2 == 0) {
            out[p.s] = c2;
        }
        else {
            out[p.s] = c;
        }

        
    }

    for(auto e : out) cout << e << "\n";
}