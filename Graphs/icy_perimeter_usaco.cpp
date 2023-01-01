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
#define forr(i, j, k, in) for (int i = j; i < k; i += in)
#define frange(i, j) forr(i, 0, j, 1)
#define all(cont) cont.begin(), cont.end()
#define MP make_pair
#define PB push_back
#define f first
#define s second

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mpii;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;

vs hall;
vector<vb> visited;
int n, m;

pii floodfill(int i, int j) {
    if(i >= n || j >= m || i < 0 || j < 0) return pii{0, 1};
    if(visited[i][j]) return pii{0, 0};
    if(hall[i].at(j) == '.') return pii{0, 1};
    visited[i][j] = true;
    pii out;
    out.f = 1;
    out.s = 0; //(j == 0 || hall[i].at(j-1)=='.') + (j == (n-1) || hall[i].at(j+1)=='.') + (i == (n-1) || hall[i].at(i+1)=='.') + (i == 0 || hall[i].at(i-1)=='.');
    pii val;
    val = floodfill(i+1, j);
    out.f += val.f;
    out.s += val.s;
    val = floodfill(i-1, j);
    out.f += val.f;
    out.s += val.s;
    val = floodfill(i, j+1);
    out.f += val.f;
    out.s += val.s;
    val = floodfill(i, j-1);
    out.f += val.f;
    out.s += val.s;
    return out;
    
}

bool comp(pii &x, pii &y) {
    if(x.f > y.f) return true;
    else if(x.f == y.f) {
        if(x.s < y.s) return true;
    }
    return false;
}

int main()
{

    freopen("perimeter.in", "r", stdin);
    freopen("perimeter.out", "w", stdout);
    scd(n); 
    m = n;
    string a;
    hall = vs(n);
    visited = vector<vb>(n, vb(m, false));
    frange(i, n) {
        cin >> a;
        hall[i] = a;
    }
    int rooms = 0;
    vii ar_peri;
    frange(i, n) {
        frange(j, m) {
            if(!visited[i][j]) {
                pii out = floodfill(i, j);
                ar_peri.PB(out);
            }
            
        }
    }
    sort(all(ar_peri), comp);
    cout << ar_peri[0].f << " " << ar_peri[0].s << "\n";
    
    
    return 0;
}
