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

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return x ^ RANDOM; }
};


queue<pair<string, int>> q;
bitset<987654211> vis;

void move(string &x, int i, int j, int d) {
    swap(x[i], x[j]);
    if(!vis[stoi(x)]) {
        vis[stoi(x)] = true;
        q.push(mp(x, d));
    }
    swap(x[i], x[j]);
}

int main() {
    // usaco();
    string str = "";
    frange(i, 9) {
        int a;
        scd(a);
        str += char('0' + a);
    }

    q.push(mp(str, 0));

    

    while(q.size()) {
        auto p = q.front();
        q.pop();
        if(p.f == "123456789") {
            printf("%d", p.s);
            return 0;
        }

        frange(j, 9) {
            if(j != 0 && j != 3 && j != 6) {
                move(p.f, j, j-1, p.s+1);
            }
            if(j != 2 && j != 5 && j != 8) {
                move(p.f, j, j+1, p.s+1);
            }
            if(j - 3 >= 0) {
                move(p.f, j, j-3, p.s+1);
            }
            if(j + 3 < 9) {
                move(p.f, j, j+3, p.s+1);
            }
        }
    }

    // printf("%d\n", dist[mv[123456789]]);

}