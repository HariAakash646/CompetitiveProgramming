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
struct BIT2D
{
    int mx, my;
    vector<vector<T>> bit;
    vector<vector<T>> vec;

    BIT2D(int x, int y) : mx(x), my(y), bit(x+1, vector<T>(y+1)), vec(x+1, vector<T>(y+1)) {}

    int lsb(int x)
    {
        return x & (-x);
    }

    void set(int x, int y, T v)
    {
        add(x, y, v - vec[x][y]);
    }

    void change(int x, int y) {
        set(x, y, !vec[x][y]);
    }

    void add(int x, int y, T v)
    {
        if (x == 0 || y == 0)
            return;
        vec[x][y] += v;
        while (x <= mx)
        {
            int y1 = y;
            while(y1 <= my) 
            {   bit[x][y1] += v;
                y1 += lsb(y1);
            }
            x += lsb(x);
        }
    }

    T query(int x, int y)
    {
        T tot = 0;
        if (x == 0 || y == 0)
            return tot;
        
        while (x >= 1)
        {
            int y1 = y;
            while(y1 >= 1) 
            {   tot += bit[x][y1];
                y1 -= lsb(y1);
            }
            x -= lsb(x);
        }
        return tot;
    }

    T query(int x1, int y1, int x2, int y2) {
        // x2 >= x1 && y2 >= y1
        return query(x2, y2) - query(x1-1, y2) - query(x2, y1-1) + query(x1-1, y1-1);
    }
};

int main() {
    // usaco();
    int n, q;
    scd(n);
    scd(q);

    vvi grid(n+1, vi(n+1));
    frange(i, n) {
        string str;
        cin >> str;
        frange(j, n) grid[i+1][j+1] = (str[j] == '*');
    }

    BIT2D<lli> bit(n, n);

    forr(i, 1, n+1) {
        forr(j, 1, n+1) bit.set(i, j, grid[i][j]);
    }

    frange(_, q) {
        int t;
        scd(t);
        if(t == 1) {
            int x, y;
            scd(x);
            scd(y);
            bit.change(x, y);
        }
        else {
            int x1, y1, x2, y2;
            scd(x1);
            scd(y1);
            scd(x2);
            scd(y2);
            printf("%lld\n", bit.query(x1, y1, x2, y2));
        }
    }

}