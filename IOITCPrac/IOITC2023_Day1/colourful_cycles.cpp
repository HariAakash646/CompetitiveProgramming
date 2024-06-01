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

vi disset, sze;

int findf(int x) {
    while(x != disset[x]) {
        x = disset[x];
    }
    return x;
}

stack<pii> stk;

bool unionf(int x, int y) {
    x = findf(x);
    y = findf(y);
    if(x == y) return false;
    if(sze[y] > sze[x]) swap(x, y);
    disset[y] = x;
    sze[x] += sze[y];
    stk.push(mp(x, y));
    return true;
}

vector<vii> same;

bool cmp(int x, int y) {
    return same[x].size() > same[y].size();
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, m, k;
        scd(n);
        scd(m);
        scd(k);

        vi col(n+1);
        forr(i, 1, n+1) {
            scd(col[i]);
        }

        same = vector<vii>(k+1);

        vector<map<int, vii>> edg(k+1);
        vii tmp;
        frange(i, m) {
            int a, b;
            scd(a);
            scd(b);
            if(col[a] == col[b]) 
                same[col[a]].pb(mp(a, b));
            else
                tmp.pb(mp(a, b));
        }

        vi vert;
        forr(i, 1, k+1) vert.pb(i);
        sort(all(vert), cmp);
        vi pos(k+1);
        frange(i, k) pos[vert[i]] = i;

        for(auto p : tmp) {
            int a = p.f;
            int b = p.s;
            if(pos[col[a]] > pos[col[b]]) swap(a, b);
            edg[col[a]][col[b]].pb(mp(a, b));
        }

        disset = sze = vi(n+1, 1);
        frange(i, n+1) disset[i] = i;

        lli c = 0;
        int uc = k;

        vb vis(k+1);
        stk = {};

        forr(i, 1, k+1) {

            for(auto p : same[i]) {
                if(!unionf(p.f, p.s)) {
                    uc--;
                    c += uc;
                    vis[i] = true;
                    break;
                }
            }
            while(stk.size()) {
                auto p1 = stk.top();
                stk.pop();
                disset[p1.s] = p1.s;
                sze[p1.f] -= sze[p1.s];
            }
        }
        
        
        for(auto i : vert) {
            if(vis[i]) continue;
            stk = {};
            for(auto p : same[i]) {
                // printf("%d %d\n", p.f, p.s);
                unionf(p.f, p.s);
            }
            int sz = stk.size();
            for(auto p : edg[i]) {
                if(vis[p.f]) continue;

                for(auto p1 : same[p.f]) {
                    unionf(p1.f, p1.s);
                }

                for(auto e : p.s) {
                    // printf("%d %d %d %d\n", i, p.f, e.f, e.s);
                    if(!unionf(e.f, e.s)) {

                        c++;
                        break;
                    }
                }
                while((int)stk.size() > sz) {
                    auto p1 = stk.top();
                    stk.pop();
                    disset[p1.s] = p1.s;
                    sze[p1.f] -= sze[p1.s];
                }
            }
            while(stk.size()) {
                auto p1 = stk.top();
                stk.pop();
                disset[p1.s] = p1.s;
                sze[p1.f] -= sze[p1.s];
            }
        }
        printf("%lld\n", c);
    }

}