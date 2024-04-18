#include <bits/stdc++.h>
#include "robots.h"

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

vii toy;
vi weak, sma;
int a, b, t;

bool check(int x) {
    vb vis(t);
    priority_queue<pair<int, int>> pq;
    int id = 0;
    for(auto p : weak) {
        forr(i, id, t) {
            if(toy[i].f < p) {
                pq.push({toy[i].s, i});
                id = i+1;
            }
            else {
                id = i;
                break;
            }
        }
        int c = 0;
        while(pq.size()) {
            auto e = pq.top();
            vis[e.s] = true;
            pq.pop();
            c++;
            if(c >= x) break;
        }
    }
    priority_queue<int> pq2;
    frange(i, t) {
        if(!vis[i]) {
            pq2.push(toy[i].s);
        }
    }
    for(auto p : sma) {
        int c = 0;
        while(pq2.size()) {
            if(pq2.top() >= p) return false;
            pq2.pop();
            c++;
            if(c >= x) break;
        }
    }
    return pq2.empty();

}

int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {
    a = A;
    b = B;
    t = T;
    toy = vii(t);
    frange(i, t) {
        toy[i] = mp(W[i], S[i]);
    }
    sort(all(toy));
    weak = vi(a);
    frange(i, a) {
        weak[i] = X[i];
    }
    sma = vi(b);
    frange(i, b) {
        sma[i] = Y[i];
    }

    sort(all(weak));
    sort(all(sma), greater<int>());

    int lo = 1;
    int hi = t+1;

    while(lo != hi) {
        int mid = (lo + hi)/2;
        if(check(mid)) {
            hi = mid;
        }
        else {
            lo = mid+1;
        }
    }
    if(lo <= t) return lo;
    else
    return -1;
}

// int main() {
//     usaco();
//     int a, b, t;
//     scd(a);
//     scd(b);
//     scd(t);
//     int X[a], Y[b], W[t], S[t];

//     frange(i, a) {
//         scd(X[i]);
//     }

//     frange(i, b) {
//         scd(Y[i]);
//     }

//     frange(i, t) {
//         scd(W[i]);
//         scd(S[i]);
//     }


//     printf("%d", putaway(a, b, t, X, Y, W, S));
// }