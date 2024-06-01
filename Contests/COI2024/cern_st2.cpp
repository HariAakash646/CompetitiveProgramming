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
        if(r - l+1 <= 4) {
            seti st;
            forr(i, l, r+1) {cnt[vec[i]]++; st.insert(vec[i]);}
            int c = 0, c2 = 0;
            int ma = 0;
            for(auto i : st) {
                if(cnt[i]) {
                    c++;
                    if(cnt[i] >= 2) c2++;
                    ma = max(ma, cnt[i]);
                }
            }       
            int len = r - l + 1;
            if(ma > len/2) {
                out[j] = 1;
            }
            else if(len % 2 == 0 && ma == len / 2) {
                if(c == 2)
                    out[j] = 0;
                else out[j] = 1;
            }
            else if(len % 2 == 0) {
                out[j] = c2;
            }
            else {
                out[j] = c;
            }
            forr(i, l, r+1) cnt[vec[i]]--;
        }
        else {
            quer.pb(mp(mp(r, l), j));
        }
        
    }
    sort(all(quer));
    int en = 0;
    vi pre(n+1), pre2(n+1);
    BIT<int> bit(n+1), bit2(n+1);
    for(auto p : quer) {
        int l = p.f.s;
        int r = p.f.f;
        while(en < r) {
            en++;
            if(pre[vec[en]]) bit.set(pre[vec[en]], 0);
            if(pre[vec[en]]) {
                if(pre2[vec[en]]) bit2.set(pre2[vec[en]], 1);
                bit2.set(pre[vec[en]], 1);
            }
            pre2[vec[en]] = pre[vec[en]];
            pre[vec[en]] = en;
            bit.set(en, 1);
        }
        if((r-l+1)%2)
            out[p.s] = bit.query(en)-bit.query(l-1);
        else out[p.s] = bit2.query(en)-bit2.query(l-1);
    }

    for(auto e : out) cout << e << "\n";
}