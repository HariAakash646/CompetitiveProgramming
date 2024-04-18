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

int n;

void out_bin(int x) {
    string out;
    frange(i, n) out += '0';

    frange(i, n) {
        if(x & (1<<i)) out[i] = '1';
    }
    reverse(all(out));
    cout << out << "\n";
}

int main() {
    
    scd(n);

    int st = 0;
    vb vis(1<<n);

    frange(i, 1<<n) {
        vis[st] = true;
        out_bin(st);
        frange(j, n) {
            if(!vis[st ^ (1<<j)]) {
                st = st ^ (1<<j);
                break;
            }
        }
    }
}