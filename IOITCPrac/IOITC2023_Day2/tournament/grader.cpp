#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl "\n" // remove in interactive
#endif

void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}


namespace{
    vector<vector<int>> adj;
    int T, Q, N, asked;
}

int getNode(int n);

bool isEdge(int i, int j){
    if(Q == 0){
        cout << "Too many Queries" << endl;
        exit(0);
    }
    if(i == j || min(i, j) < 0 || max(i, j) >= N){
        cout << "Invalid query\n" << endl;
        cout << 0 << endl;
        exit(0);
    }
    Q--;
    asked++;
    return adj[i][j];
}

struct graph{
    vector<vector<int>> adj;
    int n;
    graph(){}
    graph(int n) : n(n), adj(n){}
    void add_edge(int a, int b){
        adj[a].push_back(b);
    }
    vector<int> distances(int s){
        const int INF = 1e9;
        vector<int> D(n, INF); D[s] = 0; 
        queue<int> q; q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            int d = D[u];
            for(int v : adj[u]) if(D[v] == INF){
                D[v] = d + 1;
                q.push(v);
            }
        }
        return D;
    }
};

int main(){
    usaco();
    cin >> T;
    Q = 2000000;
    asked = 0;

    while(T--){
        cin >> N;
        adj.clear();
        adj.resize(N);

        graph G(N);

        for(int i = 0; i < N; i++){
            adj[i].resize(N);
            string s; cin >> s;
            for(int j = 0; j < N; j++){
                adj[i][j] = (s[j] == '1');
                if(adj[i][j]) G.add_edge(i, j);
            }
        }
        
        int x = getNode(N);

        if(x < 0 || x >= N){
            cout << "Wrong Answer!" << endl;
            exit(0);
        }

        vector<int> D = G.distances(x);

        if(*max_element(all(D)) > 3){
            cout << "Wrong Answer!" << endl;
            exit(0);
        }
    }
    cout << "Correct output!" << endl;
    cout  << "Queries Asked: " << asked << endl;
}