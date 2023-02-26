#include <bits/stdc++.h>
#include <iostream>

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
#define pb push_back
#define mp make_pair
#define f first
#define s second
typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<lli> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;

vi vec;
vb vis;
vi stk;
int tot = 0;

void dfs(int n, int curr) {
    vis[n] = true;
    stk[n] = curr;
    int e = vec[n];
    if(stk[e]) tot += 1 + stk[n] - stk[e];
    else if(!vis[e]) dfs(e, curr+1);
    stk[n] = 0;
}

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n;
    scd(n);
    vec = vi(n+1);
    vis = vb(n+1);
    stk = vi(n+1);
    frange(i, n) {
        scd(vec[i+1]);
    }
    forr(i, 1, n+1){
        if(!vis[i]) {
            dfs(i, 1);
        }
    }
    printf("%d", tot);
}
