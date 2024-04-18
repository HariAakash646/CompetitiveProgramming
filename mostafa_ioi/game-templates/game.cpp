#include "game.h"
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

int n;
vi disset;
vvi num_con;

int findf(int x) {
    if(x == disset[x]) {
        return x;
    }
    disset[x] = findf(disset[x]);
    return disset[x];
}

void unionf(int u, int v) {
    u = findf(u);
    v = findf(v);
    if(u == v) return;
    disset[u] = v;

    frange(i, n) {
        num_con[v][i] += num_con[u][i];
        num_con[i][v] += num_con[i][u];
    }
}

void initialize(int N) {
    n = N;
    disset = vi(n);
    frange(i, n) disset[i] = i;
    num_con = vvi(n, vi(n));
    frange(i, n) {
        frange(j, n) {
            if(i != j) num_con[i][j] = 1;
        }
    }
}

int hasEdge(int u, int v) {
    int ut = findf(u);
    int vt = findf(v);
    if(ut == vt) return 0;
    num_con[ut][vt]--;
    num_con[vt][ut]--;
    if(num_con[ut][vt] == 0) {
        unionf(ut, vt);
        return 1;
    }
    return 0;
}
