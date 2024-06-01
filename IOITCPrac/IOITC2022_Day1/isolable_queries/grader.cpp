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

vector<pair<int, int>> getEdges(int n);

pair<int, int> query(vector<int> S){
    vector<int> S0 = S;
    if(Q == 0){
        cout << "Too many queries" << endl;
        exit(0);
    }
    int num_nodes = S.size();
    // trace(S, adj);
    vector<int> present(N);
    for(int &i: S){
        i--;
        if(i < 0 || i >= N){
            cout << "All values in V must be in the range [1, n]" << endl;
            exit(0);
        }
        if(present[i]){
            cout << "Duplicate values in S" << endl;
            exit(0);
        }
        present[i] = 1;
    }

    if(num_nodes < 2){
        cout << "The size of S must be at least 2\n" << endl;
        exit(0);
    }

    vector<int> subtree_size(N);

    function<int(int, int)> getSize = [&](int s, int p){
        subtree_size[s] = present[s];
        for(int v: adj[s]) if(v != p){
            subtree_size[s] += getSize(v, s);
        }
        return subtree_size[s];
    };
    getSize(0, 0);
    
    vector<int> isolable;
    function<void(int, int)> dfs = [&](int s, int p){
        int tot = num_nodes != subtree_size[s];
        for(int v: adj[s]) if(v != p){
            tot += subtree_size[v] != 0;
            dfs(v, s);
        }
        if(present[s] && tot == 1) isolable.push_back(s);
    };
    dfs(0,0);
    Q--;
    asked++;
    int some = isolable[rand() % isolable.size()] + 1;
    int sum = accumulate(isolable.begin(), isolable.end(), 0) + isolable.size();
    // trace(S0, leaf, sum);
    return {some, sum};
}

struct dsu{
    int n;
    vector<int> par;
    dsu(int n) : n(n), par(n){
        iota(par.begin(), par.end(), 0);
    }
    int root(int x){
        return x == par[x] ? x : (par[x] = root(par[x]));
    }
    bool merge(int x, int y){
        x = root(x); y = root(y);
        if(x == y) return 0;
        par[x] = y;
        return 1;
    }
};

int main(){
    usaco();
    cin >> T >> Q;
    asked = 0;
    while(T--){
        cin >> N;
        int n = N;
        adj.clear(); adj.resize(n);
        vector<pair<int, int>> expected;
        dsu D(N);
        for(int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
            if(u > v) swap(u, v);
            expected.push_back({u + 1, v + 1});
            if(!D.merge(u, v)){
                cout << "The input must be a tree" << endl;
                exit(0);
            }
        }
        sort(expected.begin(), expected.end());

        vector<pair<int, int>> contestant = getEdges(n);
        for(auto& it: contestant) if(it.first > it.second) swap(it.first, it.second);
        sort(contestant.begin(), contestant.end());

        if(expected != contestant){
            cout << "Incorrect output!\n" << endl;
            exit(0);
        }
    }
    cout << "Correct output!" << endl;
    cout  << "Queries Asked: " << asked << endl;
}