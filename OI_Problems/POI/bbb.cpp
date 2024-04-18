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
    int n, p, q, x, y;
    scd(n);
    scd(p);
    scd(q);
    scd(x);
    scd(y);
    string str;
    cin >> str;
    int v = p;
    int tot = 0;
    frange(i, n) {
        if(str[i] == '+') v++;
        else v--;
    }
    if(v >= q) {
        int id = n-1;
        frange(i, (v-q)/2) {
            while(str[id] == '-') id--;
            str[id] = '-';
            id--;
            tot += x;
        }
    }
    else {
        int id = 0;
        frange(i, (q-v)/2) {
            while(str[id] == '+') id++;
            str[id] = '+';
            id++;
            tot += x;
        }
    }
    v = p;
    int id = n-1;
    int mi = p;
    int pos = -1;
    frange(i, n) {
        if(str[i] == '+') v++;
        else v--;
        if(v < mi) {
            mi = v;
            pos = i;
        }
    }

    mi = -mi;

    if(mi <= 0) printf("%d", tot);
    else {
        vi suf(n);
        if(str[n-1]=='+') suf[n-1] = 1;
        else suf[n-1] = -1;
        for(int i=n-2; i>=0; i--) {
            suf[i] = suf[i+1];
            if(str[i] == '+') suf[i]++;
            else suf[i]--;
        }

        int v = (mi / 2) * 2 * x;
        if(mi % 2) v += 2 * x;

        for(int i=n-1; i>=0; i--) {
            int k = mi - suf[i];
            int vl = y * (n-i);
            
            if(k > 0) {
                if((k+1)/2 > i-pos-1) continue;
                vl += (k / 2) * 2 * x;
                        if(k % 2) vl += 2*x;}
            v = min(v, vl);
        }
        
        printf("%d", tot+v);
    }
    

}