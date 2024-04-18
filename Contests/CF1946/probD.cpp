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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, x;
        scd(n);
        scd(x);
        vi vec(n);
        frange(i, n) scd(vec[i]);

        
        int k = -1;
        frange(i, 32) {
            if(i!= 0 && (x & (1<<(i-1))) == 0) continue;
            int id = -1;
            int pre = 0;
            bool done = true;
            int c = 0;
            // printf("%d ", i);
            while(true) {
                int v = 0;
                pre = id;
                c++;
                while(id + 1 < n) {
                    v = v^vec[id+1];
                    bool br = true;
                    for(int j=31; j>=i; j--) {
                        if(!(x&(1<<j)) && (v&(1<<j))) {
                            br = false;
                            break;
                        }
                    }
                    
                    if(br && i - 1 >= 0) {
                        if((v&(1<<(i-1)))) br = false;
                    }
                    id++;
                    if(br) break;
                }
                // printf("%d ", id);
                if(id == n-1) {
                    bool br = true;
                    for(int j=31; j>=i; j--) {
                        if(!(x&(1<<j)) && (v&(1<<j))) {
                            br = false;
                            break;
                        }
                    }
                    
                    if(br && i - 1 >= 0) {
                        if((v&(1<<(i-1)))) br = false;
                    }
                    done = br;
                    break;
                }
                
            }
            // printf("\n");
            if(done) k = max(k, c);
        }
        printf("%d\n", k);

    }
}