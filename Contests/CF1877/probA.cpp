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

int main() {
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        int n, p;
        scd(n);
        scd(p);
        priority_queue<pii> pq, pq2;
        vii vec(n);
        frange(i, n) {
            int a, b;
            scd(a);
            vec[i].s = a;
        }
        frange(i, n) {
            int b;
            scd(b);
            vec[i].f = -b;
        }
        frange(i, n) pq.push(vec[i]);
        lli tot = 0;
        pq2.push(mp(-p, 1e9));

        while(pq.size()) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq2.top();
            pq2.pop();
            tot += p2.f;
            p2.s--;
            if(p2.s > 0) pq2.push(p2);
            pq2.push(p1);
        }
        printf("%lld\n", -tot);
    }
}