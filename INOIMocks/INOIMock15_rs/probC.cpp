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
    freopen("tallbarn.in", "r", stdin);
   freopen("tallbarn.out", "w", stdout);
}

int main() {
    // usaco();
    int n;
    scd(n);
    vi vec(n);
    frange(i, n) scd(vec[i]);
    lli tot = 0;
    frange(i, n) {
        tot += vec[i];
        // printf("%d %d %d \n", i, i, vec[i]);
        for(int j=i+1; j<n; j++) {
            map<int, int> pi;
            map<int, seti> ip;
            set<pii> val;
            forr(k, i, j+1) {
                ip[vec[k]].insert(k);
                pi[k] = vec[k];
                val.insert(mp(vec[k], k));
            }
            while(pi.size() > 1) {
                pii p = *val.begin();
                val.erase(val.begin());
                int e = p.f;
                int id = p.s;
                
                
                auto it2 = pi.find(id);
                bool done = false;
                if(it2 != pi.begin()) {
                    it2--;
                    if((*it2).s <= e) {
                        done = true;
                        pii p1 = mp((*it2).s, (*it2).f);
                        if(val.find(p1) != val.end()) val.erase(p1);
                        pi.erase(it2);
                        
                        pi[id] = e+1;
                        val.insert(mp(e+1, id));

                    }
                    it2++;
                }
                if(!done && it2 != prev(pi.end())) {
                    it2++;
                    if((*it2).s <= e) {
                        done = true;
                        pii p1 = mp((*it2).s, (*it2).f);
                        if(val.find(p1) != val.end()) val.erase(p1);
                        pi.erase(it2);
                        pi[id] = e+1;
                        val.insert(mp(e+1, id));
                    }
                }
                
            }
            // printf("%d %d %d\n", i, j, (*val.begin()).f);
            tot += (*val.begin()).f;



        }
    }
    printf("%lld", tot);
}