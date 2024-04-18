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

lli compute(lli x) {
    vi num;

    frange(i, 19) {
        num.pb((x % 10));
        x/=10;
    }
    reverse(all(num));
    vector<vll> dpl(19, vll(10)), dpu(19, vll(10));
    bool done = true;
    frange(i, 19) {
        lli totl = 0, totu = 0;;
        if(i > 0) {
            frange(j, 10) {
                totl += dpl[i-1][j];
                totu += dpu[i-1][j];
            }
        }
        
        frange(j, 10) {
            if(j < num[i]) {
                int pre = 0;
                if(i > 0) pre = num[i-1];
                if(j != 4 && (j != 3 || pre != 1) && done) dpl[i][j]++;
                if(j == 4 || (j == 3 && pre == 1) || !done) dpu[i][j]++;
            }
            if(i == 0) continue;
            
            dpu[i][j] += totu;
            if(j == 4) {
                dpu[i][j] += totl;
            }
            if(j == 3) {
                dpu[i][j] += dpl[i-1][1];
            }
            if(j != 4) {
                dpl[i][j] += totl;
                if(j == 3) dpl[i][j] -= dpl[i-1][1];
            }
            
        }
        if(num[i] == 4) done = false;
        if(num[i] == 3) {
            if(i > 0 && num[i-1] == 1) done = false;
        }
    }
    lli tot = 0;
    frange(i, 10) tot += dpu[18][i];
    return tot;

}



int main() {
    // usaco();
    int n;
    scd(n);

    frange(_, n) {
        int t;
        scd(t);
        lli x;
        sclld(x);
        if(t == 2) {
            lli d = 0;
            lli og = x;
            lli lo = x;
            lli hi = 1e18-1;
            while(lo != hi) {
                lli mid = (lo+hi)/2;
                lli x = mid;
                int pre = 0;
                bool done = true;
                while(x) {
                    int v = x % 10;
                    x /= 10;
                    if(v == 4) done = false;
                    if(v == 1 && pre == 3) done = false;
                    pre = v;
                }
                if(mid-compute(mid)-(!done) >= og) hi = mid;
                else lo = mid+1;
            }

            printf("%lld\n", lo);
        }
        else {
            int pre = 0;
            bool done = true;
            lli og = x;
            while(x) {
                int v = x % 10;
                x /= 10;
                if(v == 4) done = false;
                if(v == 1 && pre == 3) done = false;
                pre = v;
            }
            if(!done) printf("-1\n");
            else {
                og -= compute(og);
                printf("%lld\n", og);
            }
        }
    }
    
}