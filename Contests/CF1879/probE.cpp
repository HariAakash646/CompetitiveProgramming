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

int main() {
    // usaco();
    int n;
    scd(n);
    vvi graph(n+1);
    vi par(n+1);
    forr(i, 2, n+1) {
        int p;
        scd(p);
        graph[p].pb(i);
        par[i] = p;
    }
    vi col(n+1);
    queue<int> q;
    for(auto e : graph[1]) {
        col[e] = 1;
        q.push(e);
    }
    int c = 1;
    map<pair<pii, int>, int> m;
    m[mp(mp(1, 0), 0)] = 1;
    while(q.size()) {
        auto x = q.front();
        q.pop();
        
        int cnt = 0;
        cnt += graph[x].size();
        if(cnt) c = max(c, 2);
        pair<pii, int> curr, curr2;
        
        if(cnt)
            {
                if(col[x] == 1) {
                    curr.f.f = 1;
                    curr.f.s = cnt;
                    curr.s = 0;
                    curr2.f.f = 1;
                    curr2.f.s = 0;
                    curr2.s = cnt;
                }
                else if(col[x] == 2) {
                    curr.f.f = cnt;
                    curr.f.s = 1;
                    curr.s = 0;
                    curr2.f.f = 0;
                    curr2.f.s = 1;
                    curr2.s = cnt;
                }
                else {
                    curr.f.f = cnt;
                    curr.f.s = 0;
                    curr.s = 1;
                    curr2.f.f = 0;
                    curr2.f.s = cnt;
                    curr2.s = 1;
                }
                
                if(m.find(curr) != m.end()) {
                    if(m[curr] != col[x]) {
                        m[curr2] = col[x];
                        c=3;
                        int r = 3;
                        if(col[x] == 3) r = 2;
                        for(auto e : graph[x]) {
                            col[e] = r;
                        }
                    }
                    else {
                        int r = 1;
                        if(col[x] == 1) r = 2;
                        for(auto e : graph[x]) {
                            col[e] = r;
                        }
                    }
                }
                else if(c == 3 && m.find(curr2) != m.end()) {
                    if(m[curr2] != col[x]) {
                        m[curr] = col[x];
                        c=3;
                        int r = 1;
                        if(col[x] == 1) r = 2;
                        for(auto e : graph[x]) {
                            col[e] = r;
                        }
                    }
                    else {
                        int r = 3;
                        if(col[x] == 3) r = 2;
                        for(auto e : graph[x]) {
                            col[e] = r;
                        }
                    }
                }
                else {
                    m[curr] = col[x];
                    int r = 1;
                    if(col[x] == 1) r = 2;
                    for(auto e : graph[x]) {
                        col[e] = r;
                    }
                }
            }
        for(auto e : graph[x]) q.push(e);
    }
    printf("%d\n", c);
    forr(i, 2, n+1) printf("%d ", col[i]);
    printf("\n");
    fflush(stdout);

    while(true) {
        int v;
        scd(v);
        if(v == -1) {
            return 0;
        }
        else if(v == 1) {
            return 0;
        }
        else {
            pair<pii, int> p=mp(mp(0, 0), 0);
            forr(i, 1, c+1) {
                int v;
                scd(v);
                if(i == 1) p.f.f+=v;
                else if(i == 2) p.f.s+=v;
                else p.s+=v;
            }
            printf("%d\n", m[p]);
            fflush(stdout);
        }
    }
}