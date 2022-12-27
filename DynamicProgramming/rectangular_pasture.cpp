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
typedef pair<int, int> pii;
typedef vector<int> vi;
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

bool ycomp(pii x, pii y) {return x.second < y.second;}

int prefix2d(vvi &table, int x1, int y1, int x2, int y2) {
    int maxx = max(x1, x2);
    int maxy = max(y1, y2);
    int minx = min(x1, x2) - 1;
    int miny = min(y1, y2) - 1;
    return table[maxx][maxy] - table[maxx][miny] - table[minx][maxy] + table[minx][miny];
    
}


int main() {
    
    int n;
    scd(n);
    
    vii grid(n);
    frange(i, n) {
        scd(grid[i].first); scd(grid[i].second);
    }
    sort(grid.begin(), grid.end());
    frange(i, n) grid[i].first = i+1;
    sort(grid.begin(), grid.end(), ycomp);
    frange(i, n) grid[i].second = i+1;
    
    vvi table(n+1, vi(n+1, 0));
    for(pii p : grid) table[p.first][p.second] = 1;
    forr(i, 1, n+1, 1) {
        forr(j, 1, n+1, 1) {
            table[i][j] = table[i][j] + table[i-1][j] + table[i][j-1] - table[i-1][j-1];
        }
    }
    long long c = grid.size()+1;
    int a, b;
    frange(i, n) {
        forr(j, i+1, n, 1) {
            if(grid[i].second > grid[j].second) {
                a = prefix2d(table, grid[i].first, grid[i].second, grid[j].first, n);
                b = prefix2d(table, grid[j].first, grid[j].second, grid[i].first, 1);
            }
            else {
                a = prefix2d(table, grid[j].first, grid[j].second, grid[i].first, n);
                b = prefix2d(table, grid[i].first, grid[i].second, grid[j].first, 1);
            }
            c += a * b;
        }
    }
    printf("%lld", c);
    
    return 0;
}
