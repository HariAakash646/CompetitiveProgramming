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
    int n;
    scd(n);
    vi vec(2*n+1);
    vector<seti> boy(n+1), girl(n+1);
    forr(i, 1, 2*n+1) {
        scd(vec[i]);
        if(vec[i] > 0) boy[vec[i]].insert(i);
        else girl[-vec[i]].insert(i);
    }

    vb vis(2*n+1);

    BIT<int> bit(2*n+1);
    forr(i, 1, 2*n+1) {
        bit.set(i, 1);
    }
    lli tot = 0;
    forr(i, 1, 2*n+1) {
        if(!vis[i]) {
            vis[i] = true;
            int p1 = bit.query(i);
            if(vec[i] > 0) {
                boy[vec[i]].erase(i);
                int id = *girl[vec[i]].begin();
                vis[id] = true;
                girl[vec[i]].erase(girl[vec[i]].begin());
                int p2 = bit.query(id);
                bit.add(1, 1);
                bit.add(id, -1);
                tot += (p2 - p1-1);
                if(p1 % 2 == 1) tot++; 
            }
            else {
                vec[i] = -vec[i];
                girl[vec[i]].erase(i);
                int id = *boy[vec[i]].begin();
                vis[id] = true;
                boy[vec[i]].erase(boy[vec[i]].begin());
                int p2 = bit.query(id);
                bit.add(1, 1);
                bit.add(id, -1);
                tot += (p2 - p1-1);
                if(p1 % 2 == 0) tot++; 
            }
             
        }
    }
    printf("%lld", tot);
}