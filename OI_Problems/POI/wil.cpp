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
struct RMQ {
    vector<vector<T>> table;
    int n;


    int level(int x) {
        return 31 - __builtin_clz(x);
    }

    T oper(T x, T y) {
        return max(x, y);
    }

    void build(vector<T> val) {
        n = val.size();
        table = vector<vector<T>>(n, vector<T>(22));
        frange(i, n) {
            table[i][0] = val[i];
        }
        forr(j, 1, 22) {
            frange(i, n) {
                table[i][j] = oper(table[i][j-1], table[min(n-1, i+(1<<(j-1)))][j-1]);
            }
        }
    }

    T query(int l, int r) {
        int x = level(r - l + 1);
        return oper(table[l][x], table[r-(1<<x)+1][x]);
    }
};

int n, d;
lli p;
lli pref[int(2e6)];
lli val[int(2e6)];
deque<pair<lli, int>> dq;

bool check(int x) {
    x--;
    
    while(dq.size()) dq.pop_back();

    frange(i, x-d+1) {
        lli v = val[i];
        while(dq.size() && v >= dq.back().f) {
            dq.pop_back();
        }
        dq.pb(mp(v, i));
    }
    frange(i, n-x) {
        lli v = pref[i+x];
        if(i > 0) v -= pref[i-1];
        // lli ma = rmq.query(i, i+x-d);
        lli ma = dq.front().f;
        if(v - ma <= p) return true;
        if(dq.front().s == i) dq.pop_front();
        if(i + x - d + 1 < n-d) {
            lli v = val[i + x - d + 1];
            while(dq.size() && v >= dq.back().f) {
                dq.pop_back();
            }
            dq.pb(mp(v, i+x-d+1));
        }
    }
    return false;
}

int main() {
    // usaco();
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> p >> d;

    d--;

    frange(i, n) {
        cin >> pref[i];
        if(i > 0) pref[i] += pref[i-1];
    }
    frange(i, n-d) {
        val[i] = pref[i+d];
        if(i > 0) val[i] -= pref[i-1];
    }

    int lo = d+1;
    int hi = n;

    while(lo < hi) {
        int mid = (lo + hi+1)/2;
        if(check(mid)) lo = mid;
        else hi = mid-1;
    }
    cout << lo;

}