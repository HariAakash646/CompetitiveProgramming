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
    usaco();
    int r, c;
    cin >> r >> c;

    vvi gr1(r, vi(c)), gr2(r, vi(c));

    frange(i, r) {
        string row;
        cin >> row;
        frange(j, c) {
            if(row[j] == 'M') gr1[i][j] = 1;
            if(row[j] == 'S') gr2[i][j] = 1;
        }
    }

    lli tot = 0;
    lli vert = 0;
    int v = 0;
    BIT<lli> bit(c+1), bit2(c+1);
    frange(i, r) {
        
        frange(j, c) {
            if(gr1[i][j]) {
                bit.add(j+1, 1);
                bit2.add(j+1, j+1);
                v++;
            }
        }
        frange(j, c) {
            if(gr1[i][j]) {
                tot += vert;
                tot += (j+1) * bit.query(j+1) - bit2.query(j+1);
                tot += (bit2.query(c) - bit2.query(j+1)) - (j+1) * (bit.query(c) - bit.query(j+1));
            }
        }
        vert += v;
    }
    printf("%lld", tot);

}