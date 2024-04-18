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

int main() {
    // usaco();
    int n, m;
    scd(n);
    scd(m);

    vvi grid(n, vi(m));
    frange(i, n) {
        frange(j, m) {
            scd(grid[i][j]);
        }
    }

    int k, l;
    scd(k);
    scd(l);

    vvi val(n, vi(m));
    frange(i, n) {
        mseti st;
        frange(j, l) st.insert(grid[i][j]);
        frange(j, m-l+1) {
            val[i][j] = *prev(st.end());
            st.erase(st.find(grid[i][j]));
            if(j + l < m) st.insert(grid[i][j+l]);
        }
    }

    vvi out(n-k+1, vi(m-l+1));
    frange(j, m-l+1) {
        mseti st;
        frange(i, k) st.insert(val[i][j]);
        frange(i, n-k+1) {
            out[i][j] = *prev(st.end());
            st.erase(st.find(val[i][j]));
            if(i + k < n) st.insert(val[i+k][j]);
        }
    }
    frange(i, n-k+1) {
        frange(j, m-l+1) {
            printf("%d ", out[i][j]);
        }
        printf("\n");
    }
}