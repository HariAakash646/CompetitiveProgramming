#include <bits/stdc++.h>
 
using namespace std;
 
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
typedef set<int> seti;
typedef multiset<int> mseti;
typedef long double ld;
 
void usaco()
{
    // freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
    freopen("cbs.in", "r", stdin);
   freopen("cbs.out", "w", stdout);
}

int main() {
    usaco();
    int k, n;
    cin >> k >> n;
    vector<string> vec(k);
    vvi val(k, vi(n, -1));
    frange(i, k) {
        cin >> vec[i];
        stack<int> stk;
        frange(j, n) {
            if(vec[i][j] == '(') stk.push(j);
            else {
                if(stk.size()) {
                    val[i][j] = stk.top();
                    stk.pop();
                }
            }
        }
    }

    vi tot = val[0];
    // frange(j, n) {
    //     printf("%d ", tot[j]);
    // }
    // printf("\n");
    // forr(i, 1, n) {
    //     if(val[0][i] != -1) {
    //         tot.pb(mp(val[0][i], i));
    //     }
    // }
    forr(i, 1, k) {
        
        vi tmp(n, -1);
        for(int j=n-1; j>=0; j--) {
            if(val[i][j] != -1 && tot[j] != -1) {
                int j1 = val[i][j];
                int j2 = tot[j];
                while(j1 != j2 && j1 != -1 && j2 != -1) {
                    if(j1 > j2) {
                        j1 = val[i][j1-1];
                    }
                    else {
                        j2 = tot[j2-1];
                    }
                }
                if(j1 == j2) tmp[j] = j1;
                
            }
        }
        tot = tmp;
        // frange(j, n) {
        //     printf("%d ", tot[j]);
        // }
        // printf("\n");
    }
    lli out = 0;
    for(int i=n-1; i>=0; i--) {
        
        if(tot[i] != -1) {
            lli c = 0;
            int it = i;
            while(true) {
                it = tot[it];
                if(it != -1) {
                    c++;
                    it = it-1;
                }
                else break;
            }
            out += c;
        }
        // else i--;
    }
    cout << out;

}