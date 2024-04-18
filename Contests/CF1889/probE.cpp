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

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, m, k;
        scd(n);
        scd(m);
        scd(k);

        BIT<int> bit(n+5);
        vii vec(m);
        frange(i, m) {
            scd(vec[i].f);
            scd(vec[i].s);
            bit.add(vec[i].f, 1);
            bit.add(vec[i].s+1, -1);
        }

        vi out;
        int c = 0;
        forr(i, 1, n+1) {
            int v = bit.query(i);
            if(v == 0) c++;
            if(v == 1 || v == 2) out.pb(i);
        }

        vector<pair<int, pii>> val(out.size());
        frange(i, out.size()) val[i].f = out[i];
        frange(i, m) {
            if(out.empty()) break;
            auto p = vec[i];
            int id = lower_bound(all(out), p.f) - out.begin();

            forr(j, id, out.size()) {
                if(out[j] > p.s) break;
                if(!val[j].s.f) val[j].s.f = i+1;
                else val[j].s.s = i+1;
            }
        }

        vi cnt(m+1);
        map<pii, int> mv;

        for(auto p : val) {
            if(p.s.f && p.s.s) {
                mv[mp(p.s.f, p.s.s)]++;
            }
            else cnt[p.s.f]++;
        }
        vi v2;
        v2 = cnt;
        sort(all(v2), greater<>());
        int ma = v2[0] + v2[1];
        for(auto p : mv) {
            if(p.f.f && p.f.s)
                {
                    ma = max(ma, p.s + cnt[p.f.f] + cnt[p.f.s]);
                    // printf("%d %d %d\n", p.f.f, p.f.s, p.s + cnt[p.f.f] + cnt[p.f.s]);
            }
        }
        printf("%d\n", c + ma);
    }
}