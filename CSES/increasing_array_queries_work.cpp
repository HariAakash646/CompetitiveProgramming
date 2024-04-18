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
    int n, q;
    scd(n);
    scd(q);

    vll vec(n+1), pref(n+1);

    forr(i, 1, n+1) {
        sclld(vec[i]);
        pref[i] = pref[i-1] + vec[i];
    }

    deque<pii> dq;

    vector<pair<pii, int>> quer(q);

    frange(i, q) {
        scd(quer[i].f.f);
        scd(quer[i].f.s);
        quer[i].s = i;
    }

    BIT<lli> bit(n);

    sort(all(quer), greater<>());

    dq.pb(mp(n+1, 2e9));

    int l = n+1;

    vll out(q);

    for(auto p : quer) {
        while(l>p.f.f) {
            l--;
            while(dq.front().s < vec[l]) {
                auto p1 = dq.front();
                dq.pop_front();
                bit.set(p1.f, 0);
            }
            bit.add(l, (dq.front().f - l - 1) * vec[l] - (pref[dq.front().f-1] - pref[l]));
            dq.push_front(mp(l, vec[l]));
        }
        auto it = upper_bound(all(dq), mp(p.f.s, (int)2e9));
        it--;
        int id = (*it).f;
        out[p.s] = bit.query(id-1);

        out[p.s] += (p.f.s - id) * vec[id] - (pref[p.f.s] - pref[id]);
    }

    for(auto e : out) printf("%lld\n", e);

}