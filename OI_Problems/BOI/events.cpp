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

int n, q1;
vector<pair<pii, int>> dur, dur1;

vvi lift;

int binlift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) {
            x = lift[i][x];
        }
    }
    return x;
}

int main() {
    usaco();
    scd(n);
    scd(q1);
    dur = vector<pair<pii, int>>(n);
    vector<pair<pii, int>> dur2(n);
    map<int, int> mv;
    frange(i, n) {
        scd(dur[i].f.s);
        scd(dur[i].f.f);
        dur2[i] = mp(mp(dur[i].f.s, dur[i].f.f), i+1);
        dur[i].s = i+1;
        if(mv.find(dur[i].f.f) == mv.end()) {
            mv[dur[i].f.f] = dur[i].f.s;
        }
        else {
            mv[dur[i].f.f] = min(mv[dur[i].f.f], dur[i].f.s);
        }
    }

    dur1 = vector<pair<pii, int>>(n+1);
    forr(i, 1, n+1) {
        dur1[i] = dur[i-1];
    }
    sort(all(dur), greater<>());
    sort(all(dur2));
    lift = vvi(20, vi(n+1));

    deque<pii> q;
    vi lb(n+1, 1e9);
    for(auto p : dur) {
        while(q.size() && q.front().f > p.f.f) {
            q.pop_front();
        }
        if(q.size()) {
            lift[0][p.s] = q.front().s;
        }
        else lift[0][p.s] = p.s;
        if(!q.size()) q.push_back(mp(p.f.s, p.s));
        else if(p.f.s < q.back().f) q.push_back(mp(p.f.s, p.s));
        lb[p.s] = q.back().f;
    }

    forr(i, 1, n+1) printf("%d ", lb[i]);
    printf("\n");
    // q = {};
    // for(auto p : dur2) {
    //     while(q.size() && q.front().f < p.f.f) {
    //         q.pop_front();
    //     }
    //     if(q.size()) {
    //         lb[p.s] = q.front().s;
    //     }
    //     else lb[p.s] = p.f.f;

    //     if(!q.size()) q.push_back(mp(p.f.s, p.f.f));
    //     else if(p.f.s > q.back().f) q.pb(mp(p.f.s, p.f.f));
    // }
    forr(i, 1, 20) {
        forr(j, 1, n+1) {
            lift[i][j] = lift[i-1][lift[i-1][j]];
        }
    }

    frange(_, q1) {
        int u, v;
        scd(u);
        scd(v);

        if(dur1[u].f.f > dur1[v].f.f) {
            printf("impossible\n");
            continue;
        }
        else if(u == v) {printf("0\n"); continue;}

        int lo = 0;
        int hi = n;

        while(lo != hi) {
            int mid = (lo + hi)/2;
            int x = binlift(u, mid);
            if(dur1[x].f.f >= dur1[v].f.f) {
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }
        int x = binlift(u, lo);
        if(x == v) {
            printf("%d\n", lo);
            continue;
        }
        if(lo == 0) {
            printf("1\n");
            continue;
        }
        lo--;
        x = binlift(u, lo);
        if(dur1[v].f.s <= dur1[x].f.f) {
            printf("%d\n", lo+1);
            continue;
        }
        else if(mv[dur1[v].f.f] <= dur1[x].f.f) {
            printf("%d\n", lo+2);
            continue;
        }
        else {
            if(lb[v] <= dur1[x].f.f) {
                printf("%d\n", lo+2);
            }
            else printf("impossible\n");
        }

        // lo = 0;
        // hi = n;
        // while(lo != hi) {
        //     int mid = (lo + hi+1)/2;
        //     int x = binlift(u, mid);
        //     if(dur1[x].f.f >= dur1[v].f.f) {
        //         hi = mid-1;
        //     }
        //     else {
        //         lo = mid;
        //     }
        // }
        
        // x = binlift(u, lo);
        // if(dur1[v].f.s <= dur1[x].f.f) {
        //     printf("%d\n", lo+1);
        // }
        // else if(mv[dur1[v].f.f] <= dur1[x].f.f) {
        //     printf("%d\n", lo+2);
        // }
        // else {
        //     printf("impossible\n");
        // }

    }


}