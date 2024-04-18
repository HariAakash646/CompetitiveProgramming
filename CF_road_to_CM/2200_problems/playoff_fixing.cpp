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

lli mod = 998244353;

int main() {
    // usaco();
    int k;
    scd(k);

    vi vec(1<<k, -1);
    frange(i, 1<<k) {
        int a;
        scd(a);
        if(a != -1)
            vec[i] = a-1;
    }
    lli tot = 1;
    for(int i=k; i>=1; i--) {
        vi tmp(1<<(i-1), -1);
        int c = 0;
        for(int j=0; j<(1<<i); j+=2) {
            if(vec[j+1] != -1) swap(vec[j], vec[j+1]);
            if(vec[j] != -1 && vec[j+1] != -1) {
                int v1 = 31 - __builtin_clz(vec[j])+1;
                int v2 = 31 - __builtin_clz(vec[j+1])+1; 
                if(vec[j] == 0) v1 = 0;
                if(vec[j+1] == 0) v2 = 0;
                // printf("%d %d %d\n", i, v1, v2);
                if(v1 == i && v2 == i) tot = 0;
                if(v1 != i && v2 != i) tot = 0;
                tmp[j/2] = min(vec[j], vec[j+1]);
            }
            else if(vec[j] != -1) {
                int v1 = 31 - __builtin_clz(vec[j])+1;
                if(vec[j] == 0) v1 = 0;
                if(v1 != i) {
                    c++;
                    tmp[j/2] = vec[j];
                }
            }
            else {
                tot *= 2;
                tot %= mod;
                c++;
            }
        }
        forr(i, 1, c+1) {
            tot *= i;
            tot %= mod;
        }
        vec = tmp;
    }
    printf("%lld", tot);
}