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

struct line {
    lli m, c;

    lli eval(lli x) {return m * x + c;}

    ld intersect(line l) {return ld(c - l.c) / ld(l.m - m);}
};

int main() {
    // usaco();
    int n;
    scd(n);
    lli c;
    sclld(c);

    vll vec(n);
    frange(i, n) sclld(vec[i]);

    deque<line> dq;

    line curr = {-2*vec[0], vec[0]*vec[0]};
    dq.pb(curr);
    lli out = 0;
    forr(i, 1, n) {
        lli h = vec[i];
        while(dq.size() >= 2 && dq[1].eval(h) <= dq[0].eval(h)) dq.pop_front();
        lli v = dq[0].eval(h) + h * h + c;
        line curr = {-2*vec[i], v + vec[i] * vec[i]};

        while(dq.size() >= 2 && curr.intersect(dq[dq.size()-2]) <= dq.back().intersect(dq[dq.size()-2])) 
            dq.pop_back();
        dq.pb(curr);
        if(i == n-1) out = v;
    }
    printf("%lld\n", out);

}