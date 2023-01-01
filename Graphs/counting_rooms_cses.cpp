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

bool floodfill(int i, int j) {
    if(i >= n || j >= m || i < 0 || j < 0) return false;
    if(visited[i][j]) return false;
    if(hall[i].at(j) == '#') return false;
    visited[i][j] = true;
    floodfill(i+1, j);
    floodfill(i-1, j);
    floodfill(i, j+1);
    floodfill(i, j-1);
    return true;
    
}

int main()
{

    
    scd(n); scd(m);
    string a;
    hall = vs(n);
    visited = vector<vb>(n, vb(m, false));
    frange(i, n) {
        cin >> a;
        hall[i] = a;
    }
    int rooms = 0;
    frange(i, n) {
        frange(j, m) {
            bool out = floodfill(i, j);
            if(out) rooms++;
        }
    }
    cout << rooms;
    
    return 0;
}
