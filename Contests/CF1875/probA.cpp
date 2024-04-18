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
    int t;
    scd(t);
    frange(_, t) {
        int n, m, k;
        scd(n);
        scd(m);
        scd(k);
        multiset<lli> a, b;
        frange(i, n) {
            lli v;
            sclld(v);
            a.insert(v);
        }
        frange(i, m) {
            lli v;
            sclld(v);
            b.insert(v);
        }
        if(k % 2) {
            if(*prev(b.end()) > *a.begin()) {
                a.erase(a.begin());
                a.insert(*prev(b.end()));
            }
        }
        else {
            if(*prev(b.end()) > *a.begin()) {
                lli v= *a.begin();
                a.erase(a.begin());
                a.insert(*prev(b.end()));
                b.erase(prev(b.end()));
                b.insert(v);
            }
            if(*prev(a.end()) > *b.begin()){a.erase(prev(a.end()));
                        a.insert(*b.begin());}
        }
        lli tot = 0;
        for(auto e : a) tot += e;
        printf("%lld\n", tot);
    }
}