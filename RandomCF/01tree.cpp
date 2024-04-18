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
    usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);

        priority_queue<pair<int, pii>> pq;
        vi vec(n);

        frange(i, n) {
            int a;
            scd(a);
            vec[i] = a;
            pq.push(mp(a, mp(i, i)));
        }
        vb vis(n);
        bool done = true;
        while(pq.size() > 1) {
            auto p = pq.top();
            pq.pop();
            if(p.s.f == p.s.s && vis[p.s.f]) continue;
            if(p.s.f > 0 && vec[p.s.f-1] == p.f - 1) {
                vis[p.s.f-1] = true;
                vec[p.s.s] = p.f-1;
                pq.push(mp(p.f-1, mp(p.s.f-1, p.s.s)));
            }
            else if(p.s.s < n-1 && vec[p.s.s+1] == p.f-1) {
                vis[p.s.s+1] = true;
                vec[p.s.f] = p.f-1;
                pq.push(mp(p.f-1, mp(p.s.f, p.s.s+1)));
            }
            else {
                done = false;
                break;
            }
        }
        if(!done || pq.top().f != 0) printf("NO\n");
        else printf("YES\n");
    }
}