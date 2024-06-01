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

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int n, m, k;
vvi pattern;

vi val(string str, int pos) {
    if(pos == k) return {0};
    int v = 1;
    frange(i, pos) v *= 26;
    if(str[pos] != '_') {
        vi out = val(str, pos+1);
        frange(i, out.size()) out[i] += v * int(str[pos] - 'a');
        return out;
    }
    else {
        vi out = val(str, pos+1);
        vi out2;
        frange(i, 26) {
            for(auto e : out) out2.pb(e + i*v);
        }
        return out2;
    }
}

void add(string str, int id) {
    vi out = val(str, 0);
    for(auto e : out)
        pattern[e].pb(id);
}

int main() {
    // usaco();
    fastio();
    cin >> n >> m >> k;
    int sz = 1;
    frange(i, k) sz *= 26;
    pattern = vvi(sz);

    forr(i, 1, n+1) {
        string str;
        cin >> str;
        add(str, i);
    }

    vvi graph(n+1);
    vi indeg(n+1);

    forr(i, 1, m+1) {
        string str;
        cin >> str;
        int id;
        cin >> id;
        int v = val(str, 0)[0];
        bool done = false;
        for(auto e : pattern[v]) {
            if(e==id) done = true;
            else {
                graph[id].pb(e);
                indeg[e]++;
            }
        }
        if(!done) {
            cout<<("NO\n");
            return 0;
        }
    }

    queue<int> q;
    forr(i, 1, n+1) {
        if(!indeg[i]) q.push(i);
    }

    vi topo;

    while(q.size()) {
        int x = q.front();
        q.pop();
        topo.pb(x);
        for(auto e : graph[x]) {
            indeg[e]--;
            if(!indeg[e]) q.push(e);
        }
    }

    if(topo.size()!=n) cout << "NO";
    else {
        cout << "YES\n";
        for(auto e : topo) cout << e << " ";
    }
}