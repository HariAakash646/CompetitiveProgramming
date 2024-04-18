#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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

vii vec;
lli tot = 0;



string bin_str(int tot) {
    string out;
    while(tot) {
        if(tot % 2 == 1) {
            out += '1';
        }
        else out += '0';
        tot /= 2;
    }
    reverse(all(out));
    return out;
}

pii cmp(pii &x, pii &y) {
    int c1 = 31 - __builtin_clz(x.f) + x.s;
    int c2 = 31 - __builtin_clz(y.f) + y.s;

    if(c1 > c2) return x;
    else if(c2 > c1) return y;
    else {
        string s1 = bin_str(x.f);
        string s2 = bin_str(y.f);
        while(s1.size() < s2.size()) s1 += '0';
        while(s2.size() < s1.size()) s2 +='0';
        if(s1 > s2) return x;
        else return y;
    }
}

pii dfs(int x, int d) {
    pii l, r;
    if(vec[x].f > 0) {
        l = dfs(vec[x].f, d+1);
    } 
    else l = mp(-vec[x].f, d);

    if(vec[x].s > 0) {
        r = dfs(vec[x].s, d+1);
    } 
    else r = mp(-vec[x].s, d);
    return cmp(l, r);
}

int main() {
    // usaco();
    int n;
    scd(n);
    vec = vii(n+1);

    forr(i, 1, n+1) {
        int l, r;
        scd(l);
        scd(r);
        vec[i] = mp(l, r);
        // if(l < 0) tot += -l;
        // if(r < 0) tot += -r;
    }
    
    pii out = dfs(1, 1);
    string val = bin_str(out.f);
    frange(i, out.s) val += '0';
    cout << val;
}