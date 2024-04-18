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
   //  freopen("milkvisits.in", "r", stdin);
   // freopen("milkvisits.out", "w", stdout);
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
    

    vi v1(n+1), v2(n+1), p1(n+1), p2(n+1);

    forr(i, 1, n+1) {
        scd(v1[i]);
        p1[v1[i]] = i;
    }
    forr(i, 1, n+1) {
        scd(v2[i]);
        p2[v2[i]] = i;
    }
    scd(q);
    vii quer(q);
    vector<pair<pii, int>> q2;

    frange(i, q) {
        int l1, r1, l2, r2;
        scd(l1);
        scd(r1);
        scd(l2);
        scd(r2);
        quer[i] = mp(l1, r1);
        q2.pb(mp(mp(l2-1, -1), i));
        q2.pb(mp(mp(r2, 1), i));
    }
    vi out(q);
    BIT<int> bit(n);

    sort(all(q2));
    int id = 0;
    for(auto p : q2) {
        forr(i, id, p.f.f+1) {
            bit.add(p1[v2[i]], 1);
        }
        id = p.f.f + 1;
        out[p.s] += p.f.s * (bit.query(quer[p.s].s) - bit.query(quer[p.s].f - 1));
    }
    frange(i, q) {
        printf("%d\n", quer[i].s - quer[i].f + 1 - out[i]);
    }
}