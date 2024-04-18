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

int x;

char query(int id) {
    char c;
    printf("? %d\n", id);

    fflush(stdout);
    scanf("%c", &c);
    return c;
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);

        vector<BIT<int>> vec(n+1, BIT<int>(n+1));

        char c=query(1);

        x=0;

        vi out(n+1);
        

        if(c == '>') {
            int pre = 1;
            forr(i, 1, n+1) {
                c = query(i);
                if(c == '<') {
                    query(pre);
                    continue;
                }                
                while(c == '>') {
                    c = query(i);
                    pre = i;
                }
            }
            x = n;
        }
        else {
            int pre = 1;
            forr(i, 1, n+1) {
                c = query(i);
                if(c == '>') {
                    query(pre);
                    continue;
                }                
                while(c == '<') {
                    c = query(i);
                    pre = i;
                }
            }
            x = 1;
        }

        forr(i, 1, n+1) {
            forr(j, 1, n+1) vec[i].set(j, 1);
        }



        while(true) {
            pii ma = mp(0, 0);
            forr(i, 1, n+1) {
                int mi = min(vec[i].query(x), vec[i].query(n) - vec[i].query(x-1));
                ma = max(ma, mp(mi, i));
            }
            if(ma.f == 0) {
                forr(i, 1, n+1) {
                    int mi = vec[i].query(n);
                    ma = max(ma, mp(mi, i));
                }
                if(ma.f == 0) break;                
            }
            char c = query(ma.s);
            if(c == '>') {
                forr(i, 1, x+1) vec[ma.s].set(i, 0);
                x++;
            }
            else if(c == '<') {
                forr(i, x, n+1) vec[ma.s].set(i, 0);
                x--;
            }
            else {
                forr(i, 1, n+1) vec[ma.s].set(i, 0);
                out[ma.s] = x;
            }
        }
        printf("! ");
        forr(i, 1, n+1) printf("%d ", out[i]);
        // cout << endl;
        printf("\n");
        fflush(stdout);
    }
}