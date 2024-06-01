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
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input2.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

lli mod = 998244353;

int lsb(int x) {
    return x & (-x);
}

int main() {
    // usaco();
    int n, k;
    scd(n);
    scd(k);
    vll vec(n+1);
    forr(i, 1, n+1) {sclld(vec[i]); }

    vll v2(n+1);
    forr(_, 1, k+1) {
        forr(i, 1, n+1) {
            int id = i;

            while(id <=n) {
                // printf("%d\n", id);
                v2[id] += vec[i];
                v2[id] %= mod;
                // printf("%lld %lld\n", vec[i], v2[id]);
                id += lsb(id);

            }
            
        } 
        vec = v2;  
        v2 = vll(n+1);
    }
    
    forr(i, 1, n+1) printf("%lld ", vec[i]);
}