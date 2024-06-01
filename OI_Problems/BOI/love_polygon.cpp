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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}


vi nex;

int main() {
    // usaco();
    fastio();
    int n;
    cin >> n;
    map<string, int> mv;
    int id = 1;
    nex=vi(n+1);
    vi indeg(n+1);
    vvi rev(n+1);
    frange(i, n) {
        string a, b;
        cin >> a >> b;
        if(mv.find(a) == mv.end()) mv[a] = id++;
        if(mv.find(b) == mv.end()) mv[b] = id++;
        nex[mv[a]] = mv[b];
        indeg[mv[b]]++;
        rev[mv[b]].pb(mv[a]);
    }
    if(n % 2) {
        cout << -1;
        return 0;
    }
    seti st;
    forr(i, 1, n+1) {
        if(nex[nex[i]] == i && nex[i] != i) {
            st.insert(i);
            st.insert(nex[i]);
        }
    }

    forr(i, 1, n+1) {
        if(st.find(i) == st.end() && st.find(nex[i]) != st.end()) {
            nex[i] = i;
            indeg[i]++;
        }
    }

    queue<int> q;
    forr(i, 1, n+1) {
        if(!indeg[i]) q.push(i);
    }
    int c = 0;
    vb vis(n+1);
    while(q.size()) {
        int x = q.front();
        q.pop();
        if(nex[x] == x) continue;
        vis[x] = true;
        vis[nex[x]] = true;
        c++;
        indeg[nex[nex[x]]]--;
        // printf("%d %d\n", x, c);
        for(auto e : rev[nex[x]]) {
            if(!vis[e]) {
                nex[e] = e;
                indeg[e]++;
            }
        }  
        if(!indeg[nex[nex[x]]]) q.push(nex[nex[x]]);
    }

    forr(i, 1, n+1) {
        if(!vis[i]) {
            vis[i] = true;
            int x = nex[i];
            int cn = 1;
            while(x != i) {
                vis[x] = true;
                cn++;
                x = nex[x];
            }
            if(cn != 2)
                c += (cn+1)/2;
        }
    }
    cout << c;
}