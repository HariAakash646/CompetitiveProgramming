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

string str;
int n;
lli cnt = 0;
map<char, pii> mv;
bool vis[8][8] = {false};

bool fill(int x, int y) {
    if(x > 7 || y > 7 || x < 1 || y < 1 || vis[x][y]) return true;
    else return false; 
}

void dfs(int id, pii pos) {
    if(pos.f > 7 || pos.s > 7 || pos.f < 1 || pos.s < 1) return;
    if(vis[pos.f][pos.s]) return;
    
    if(id == n) {
        cnt++;
        return;
    }

    if(pos.f == 7 && pos.s == 1) return;
    // printf("%d %d %d %d\n", pos.f, pos.s, !fill(pos.f+1, pos.s), !fill(pos.f-1, pos.s));
    if((fill(pos.f-1, pos.s) && fill(pos.f+1, pos.s) && !fill(pos.f, pos.s+1) && !fill(pos.f, pos.s-1))) { return;}
    // if((fill(pos.f-1, pos.s) && !fill(pos.f, pos.s+1) && !fill(pos.f, pos.s-1))) {printf("2 %d %d\n", pos.f, pos.s); return;}
    if((fill(pos.f, pos.s-1) && fill(pos.f, pos.s+1) && !fill(pos.f+1, pos.s) && !fill(pos.f-1, pos.s))) { return;}
    // if((fill(pos.f, pos.s-1) && !fill(pos.f+1, pos.s) && !fill(pos.f-1, pos.s))) {printf("4 %d %d\n", pos.f, pos.s); return;}
    // printf("%d %d\n", pos.f, pos.s);

    vis[pos.f][pos.s] = true;

    if(str[id] == '?') {
        dfs(id+1, mp(pos.f+1, pos.s));
        dfs(id+1, mp(pos.f-1, pos.s));
        dfs(id+1, mp(pos.f, pos.s+1));
        dfs(id+1, mp(pos.f, pos.s-1));
    }
    else {
        pii p = mv[str[id]];
        dfs(id+1, mp(pos.f+p.f, pos.s+p.s));
    }

    vis[pos.f][pos.s] = false;
}

int main() {
    // usaco();
    cin >> str;
    n = str.size();

    mv['R'] = mp(0, 1);
    mv['L'] = mp(0, -1);
    mv['U'] = mp(-1, 0);
    mv['D'] = mp(1, 0);
    dfs(0, mp(1, 1));
    printf("%lld", cnt);



}