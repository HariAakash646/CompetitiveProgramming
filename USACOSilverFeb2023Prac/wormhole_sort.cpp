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

int n, m;
vi disset;
vi sizef;
vi vec;
vector<pair<pii, int>> edges;

int findf(int x) {
    while(disset[x] != x) {
        x = disset[x];
    }
    return x;
}

void unionf(int x, int y) {
    int h1 = findf(x);
    int h2 = findf(y);
    if(h1 == h2) return;
    if(sizef[h2] > sizef[h1]) swap(h1, h2);
    disset[h2] = h1;
    sizef[h1] = max(sizef[h1], 1 + sizef[h2]);
}

bool check(int x) {
    sizef = vi(n+1);
    disset = vi(n+1);
    forr(i, 1, n+1) disset[i] = i;
    for(auto e : edges) {
        if(e.s >= x) {
            unionf(e.f.f, e.f.s);
        }
    }
    forr(i, 1, n+1) {
        if(findf(i) != findf(vec[i])) return false;
    }
    return true;
}

int main() {
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    
    scd(n); scd(m);
    vec = vi(n+1);
    frange(i, n) {
        scd(vec[i+1]);
    }
    edges = vector<pair<pii, int>>(m);
    int h = 0;
    frange(i, m) {
        scd(edges[i].f.f);
        scd(edges[i].f.s);
        scd(edges[i].s);
        h = max(edges[i].s, h);
    }
    int ma = h;
    h++;
    int l = 0;
    while(l != h) {
        int mid = (l + h + 1) / 2;
        if(check(mid)) {
            l = mid;
        }
        else {
            h = mid - 1;
        }
    }
    if(l >= ma) printf("%d", -1);
    else
    printf("%d", l);
    
    
}
