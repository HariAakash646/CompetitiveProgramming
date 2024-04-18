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

int n, k;
lli s;

vi child;
vvi binlift;

int lift(int x, int c) {
    frange(i, 20) {
        if(c & (1<<i)) x = binlift[i][x];
    }
    return x;
}


int main() {
    // usaco();
    int t;
    scd(t);
    frange(_, t) {
        scd(n);
        scd(k);
        sclld(s);
        vi vec(n);
        child = vi(n+1);
        child[n] = n;
        binlift = vvi(20, vi(n+1));
        frange(i, n) scd(vec[i]);
        lli v = 0;
        int id = 0;
        frange(i, n) {
            while(id < n) {
                v += vec[id];
                if(v > s) {
                    v -= vec[id];
                    break;
                }
                id++;
            }
            child[i] = id;
            v -= vec[i];
        }
        frange(i, n+1) binlift[0][i] = child[i];
        forr(i, 1, 20) {
            frange(j, n+1) {
                binlift[i][j] = binlift[i-1][binlift[i-1][j]];
            }
        }
        int ma = 0;
        frange(i, n) {
            int v = lift(i, k) - i;
            ma = max(ma, v);
        }
        printf("%d\n", ma);

    }
}