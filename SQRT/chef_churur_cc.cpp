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
    freopen("int", "r", stdin);
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

    vll vec(n+1);
    forr(i, 1, n+1) sclld(vec[i]);
    BIT<lli> bit(n);
    forr(i, 1, n+1) bit.set(i, vec[i]);

    vii func(n+1);
    int sqn = sqrt(n);

    forr(i, 1, n+1) {
        scd(func[i].f);
        scd(func[i].s);
    }

    // vll fpref(n+1);
    // forr(i, 1, n+1) {
    //     fpref[i] = fpref[i-1] + pref[func[i].s] - pref[func[i].f-1];
    // }

    vector<BIT<lli>> cnt(sqn+1, BIT<lli>(n+1));
    vector<lli> sum(sqn+1);

    frange(i, sqn+1) {
        forr(j, 1+i*sqn, min(n+1, 1+(i+1)*sqn)) {
            cnt[i].add(func[j].f, 1);
            cnt[i].add(func[j].s+1, -1);
            sum[i] += bit.query(func[j].s) - bit.query(func[j].f-1);
        }
    }

    scd(q);
    // cout << sqn << "\n";
    frange(_, q) {
        int t;
        scd(t);
        if(t == 1) {
            int x;
            lli y;
            scd(x);
            sclld(y);
            frange(i, sqn+1) {
                int v = cnt[i].query(x);
                sum[i] += v * (y - vec[x]);
            }
            vec[x] = y;
            bit.set(x, y);
        }
        else {
            int l, r;
            scd(l);
            scd(r);
            int sqi = (l-1) / sqn;
            int sqf = (r-1) / sqn;

            lli tot = 0;

            forr(i, sqi+1, sqf) {
                tot += sum[i];
                // cout << "buck: " << i << " " <<  tot  << "\n";
            }
            forr(i, l, min(r+1, (sqi+1)*sqn+1)) {
                tot += bit.query(func[i].s) - bit.query(func[i].f-1);
                // cout << i << " " <<  tot  << "\n";
            }
            forr(i, max((sqi+1)*sqn+1, sqf*sqn+1), r+1) {
                tot += bit.query(func[i].s) - bit.query(func[i].f-1);
                // cout << i << " " <<  tot << "\n";
            }
            printf("%lld\n", tot);
        }
    }
}