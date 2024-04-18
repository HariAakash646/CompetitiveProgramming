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


int main() {
    // usaco();
    fastio();
    int t;
    cin >> t;

    frange(_, t) {
        int n;
        cin >> n;
        string str;
        cin >> str;

        vi vec(n+1);

        forr(i, 1, n+1) vec[i] = str[i-1] - '0';
        vi out;
        vi graph(n+1);
        vi indeg(n+1);
        forr(i, 1, n+1) {
            int a;
            cin >> a;
            graph[i] = a;
            indeg[a]++;
        }
        auto ind2 = indeg;
        queue<int> q;
        forr(i, 1, n+1) {
            if(!indeg[i]) q.push(i);
        }
        vb cyc(n+1, true);

        while(q.size()) {
            auto x = q.front();
            q.pop();
            cyc[x] = false;
            indeg[graph[x]]--;
            if(!indeg[graph[x]]) q.push(graph[x]);
        }
        indeg = ind2;
        lli c = 0;
        forr(i, 1, n+1) {
            if(!indeg[i]) q.push(i);
        }

        while(q.size()) {
            auto x = q.front();
            q.pop();
            if(cyc[x]) continue;
            if(vec[x]) {
                vec[x] = 0;
                c++;
                out.pb(x);
                vec[graph[x]] = !vec[graph[x]];
            }
            indeg[graph[x]]--;
            if(!indeg[graph[x]]) q.push(graph[x]);
        }

        // forr(i, 1, n+1) {
        //     printf("%d ", vec[i]);
        // }

        vb vis(n+1);
        bool done = true;
        forr(i, 1, n+1) {
            if(cyc[i] && !vis[i]) {
                int x = i;
                vis[x] = true;
                int d = 0;
                vector<pair<lli, int>> on;
                if(vec[i]) on.pb(mp(d, i));
                // cout <<  x << " ";
                while(graph[x] != i) {
                    
                    x = graph[x];
                    // cout << x << " ";
                    vis[x] = true;
                    d++;
                    if(vec[x]) on.pb(mp(d, x));
                }
                // cout << ("\n");
                // cout << on.size() << " ";
                if(on.size() % 2) {
                    done = false;
                    break;
                }
                if(on.size()) {
                    
                    lli v1 = 0;
                    lli v2 = 0;

                    for(int i=0; i<on.size(); i+=2) {
                        v1 += on[i+1].f - on[i].f;
                    }
                    for(int i=1; i<on.size()-1; i+=2) {
                        v2 += on[i+1].f - on[i].f;
                    }
                    v2 += d - on.back().f + on[0].f + 1;
                    if(v1 <= v2) {
                        for(int i=0; i<on.size(); i+=2) {
                            int e = on[i].s;
                            int p = on[i+1].s;
                            while(e != p) {
                                out.pb(e);
                                e = graph[e];
                            }
                        }
                        c += v1;
                    }
                    else {
                        for(int i=1; i<on.size()-1; i+=2) {
                            int e = on[i].s;
                            int p = on[i+1].s;
                            while(e != p) {
                                out.pb(e);
                                e = graph[e];
                            }
                        }
                        int e = on.back().s;
                        int p = on[0].s;
                        while(e != p) {
                            out.pb(e);
                            e = graph[e];
                        }
                        c += v2;
                    }
                }   
            }
        }

        if(done) {
            cout << c << "\n";
            for(auto e : out) cout << e << " ";
            cout << "\n";
        }
        else cout << "-1\n";


    }
}