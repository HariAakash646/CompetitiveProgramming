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
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    

    vi dpa(n+1, 1e9), dpb(n+1, 1e9);
    // frange(i, n) {
    //     if(s1[i] != s2[i]) {
            
    //     }
    // }
    bool done = true;
    bool curr = false;
    frange(i, n) {
        if(s1[i] != s2[i]) {
            if(s1[i] == 'A') done = curr;
            break;
        }
        if(s1[i] == 'A') curr = true;
    }

    curr = false;
    for(int i=n-1; i>=0; i--) {
        if(s1[i] != s2[i]) {
            if(s1[i] == 'B') done = done && curr;
            break;
        }
        if(s1[i] == 'B') curr = true;
    }
    if(!done) printf("-1");
    else {
        int tot = 0;
        int a = 0, b = 0;
        frange(i, n) {
            if(s1[i] != s2[i]) {
                if(s1[i] == 'B') {
                    a++;
                }
                else {
                    if(a > 0) {
                        a--;
                        tot++;
                    }
                    else b++;
                }
            }
        }
        tot += a + b;
        printf("%d\n", tot);
    }
}