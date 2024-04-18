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

struct Point {
    long long x, y;

    Point operator-(const Point &other) const {
        return {x - other.x, y - other.y};
    }

    Point(long long x, long long y) : x(x), y(y) {}
    Point() {}
};

long long cross(const Point &p, const Point &q) {
    return p.x * q.y - p.y * q.x;
}

long long orient(const Point &o, const Point &p, const Point &q) {
    return cross(p - o, q - o);
}

vector<Point> points;
static int N;
static long long queries = 0;

bool contains(const Point &i, const Point &a, const Point &b, const Point &c) {
    bool o1 = orient(a, b, i) > 0;
    bool o2 = orient(b, c, i) > 0;
    bool o3 = orient(c, a, i) > 0;

    return o1 == o2 && o2 == o3;
}

void assert_format(bool test) {
    if (!test) {
        cout << "Richiesta malformata. / Malformed query.";
        exit(1);
    }
}

bool radar(int i, int a, int b, int c) {
    assert_format(i != a && i != b && i != c && a != b && a != c && b != c);
    assert_format(0 <= i && i < N);
    assert_format(0 <= a && a < N);
    assert_format(0 <= b && b < N);
    assert_format(0 <= c && c < N);
    queries++;

    return contains(points[i], points[a], points[b], points[c]);
}


// bool radar(int i, int a, int b, int c);

vector<int> activate(int n) {
    vi nxt;
    vi out;
    
    int a = 0;
    int b = 1;
    int c = 2;
    
    forr(i, 3, n) {
        if(radar(i, a, b, c)) {
            continue;
        }
        else if(radar(a, i, b, c)) {
            a = i;
        }
        else if(radar(b, a, i, c)) {
            b = i;
        }
        else if(radar(c, a, b, i)) {
            c = i;
        }
        else nxt.pb(i);
    }
    out.pb(a);
    out.pb(b);
    out.pb(c);
    while(nxt.size()) {
        int a = nxt[0];
        vi tmp;
        forr(i, 1, nxt.size()) {
            int b = nxt[i];
            bool done = false;
            frange(j, out.size()) {
                forr(k, j+1, out.size()) {
                    if(radar(b, a, out[j], out[k])) {
                        done = true;
                        break;
                    }
                    else if(radar(a, b, out[j], out[k])) {
                        done = true;
                        a = b;
                        break;
                    }
                }
                if(done) break;
            }
            if(!done) tmp.pb(b);
        }
        out.pb(a);
        nxt = tmp;
    }
    return out;
}

int main() {
    usaco();
    // decommenta queste due righe per leggere da / scrivere su file
    // uncomment these two lines to read from / write to file
    // assert(freopen("input.txt", "r", stdin));
    // assert(freopen("output.txt", "w", stdout));

    assert(cin >> N);
    points.resize(N);
    for (auto &[x, y]: points) {
        assert(cin >> x);
        assert(cin >> y);
    }

    vector<int> ans = activate(N);
    
    cout << queries << endl;
    cout << ans.size() << '\n';
    for (int point: ans) {
        cout << point << ' ' ;
    }
    cout << '\n';
}