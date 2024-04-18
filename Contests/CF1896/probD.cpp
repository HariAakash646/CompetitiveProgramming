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
        int n, q;
        scd(n);
        scd(q);

        vi vec(n+1);
        BIT<int> bit(n+1);
        seti st;

        forr(i, 1, n+1) {
            int a;
            scd(a);
            bit.set(i, a);
            vec[i] = a;
            if(a == 1) st.insert(i);
        }

        frange(_, q) {
            int t;
            scd(t);
            if(t == 1) {
                int v;
                scd(v);
                int val = bit.query(n);
                if(val < v) {
                    printf("NO\n");
                }
                else if(val % 2 == v % 2) {
                    printf("YES\n");
                }
                else {
                    int mi = 1e9;
                    if(st.size()) {
                        mi = min(bit.query(*st.begin()), bit.query(n) - bit.query(*prev(st.end()) - 1));
                    }
                    if(val - mi >= v) {
                        printf("YES\n");
                    }
                    else printf("NO\n");
                }
            }
            else {
                int id, v;
                scd(id);
                scd(v);
                if(vec[id] == 1) st.erase(id);
                vec[id] = v;
                bit.set(id, v);
                if(v == 1) st.insert(id);
            }
        }

    }
}