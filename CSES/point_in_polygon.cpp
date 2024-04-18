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

struct pt {
    long long x, y;
    pt() {}
    pt(long long _x, long long _y) : x(_x), y(_y) {}
    pt operator-(const pt& p) const { return pt(x - p.x, y - p.y); }
    long long cross(const pt& p) const { return x * p.y - y * p.x; }
    long long cross(const pt& a, const pt& b) const { return (a - *this).cross(b - *this); }
};

int sgn(const long long& x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(long long a, long long b, long long c, long long d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool check_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
    if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
           sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    vector<pt> vec(n);

    frange(i, n) {
        sclld(vec[i].x);
        sclld(vec[i].y);
    }

    frange(_, m) {
        pt po;
        sclld(po.x);
        sclld(po.y);

        bool bound = false;
        frange(i, vec.size()-1) {
            if(check_inter(po, po, vec[i], vec[i+1])) bound = true;
        }
        if(check_inter(po, po, vec[n-1], vec[0])) bound = true;
        if(bound) {
            printf("BOUNDARY\n");
            continue;
        }
        int c = 0;
        frange(i, n-1) {
            if(check_inter(po, pt(2e9, 2e9+5), vec[i], vec[i+1])) c++;
            // if(check_inter(po, pt(2e9, 2e9), vec[i], vec[i])) c--;
        }
        if(check_inter(po, pt(2e9, 2e9+5), vec[n-1], vec[0])) c++;
        // if(check_inter(po, pt(2e9, 2e9), vec[n-1], vec[n-1])) c--;
        if(c % 2) {
            printf("INSIDE\n");
        }
        else printf("OUTSIDE\n");
    }

}