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

const lli mod = 1e9 + 7;

vector<vll> matmul(vector<vll> mat1, vector<vll> mat2) {
    int n = mat1.size();
    int m = mat2[0].size();
    vector<vll> out(n, vll(m));

    frange(i, n) {
        frange(j, m) {
            frange(k, mat2.size()) {
                out[i][j] += (mat1[i][k] * mat2[k][j]) % mod;
                out[i][j] %= mod;
            }
        }
    }

    return out;
}

vector<vll> matexp(vector<vll> mat, lli k) {
    if(k == 0) {
        vector<vll> out(mat.size(), vll(mat.size()));
        frange(i, mat.size()) out[i][i] = 1;
        return out;
    }
    vector<vll> out = matexp(mat, k/2);
    out = matmul(out, out);
    if(k % 2) out = matmul(out, mat);
    return out;
}

int main() {
    // usaco();
    lli n;
    sclld(n);

    vector<vll> mat(6, vll(6));
    frange(i, 5) {
        mat[i][i+1] = 1;
    }
    frange(i, 6) mat[5][i] = 1;
    mat = matexp(mat, n+1);

    vector<vll> vec(6, vll(1));
    vec[0][0] = 1;

    vector<vll> out = matmul(mat, vec);
    // frange(i, 6)
    printf("%lld ", out[5][0]);

}