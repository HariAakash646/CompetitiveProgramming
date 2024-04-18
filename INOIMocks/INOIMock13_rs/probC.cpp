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
 
void usaco()
{
    freopen("/media/hariaakash646/785EF1075EF0BF46/CompetitiveProgramming/input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main() {
    // usaco();
    int n;
    scd(n);
    vii vec(n);
    seti pq;
    frange(i, n) {
        scd(vec[i].f);
        scd(vec[i].s);
        if(vec[i].s < vec[i].f && vec[i].f != 1) pq.insert(i);
    }

    while(pq.size()) {
        int i = *pq.begin();
        pq.erase(pq.begin());
        int d = vec[i].f - vec[i].s;
        if(d % 2) {
            vec[i].f = vec[i].s - 1;
            vec[(i+1)%n].f = vec[(i+1)%n].f + ((d+1)/2);
            if(vec[i].f < 0) {
                vec[i].f += 2;
                vec[(i+1)%n].f -= 1;
            }
        }
        else {
            vec[i].f = vec[i].s;
            vec[(i+1)%n].f  = vec[(i+1)%n].f + (d/2);
        }
        int id = (i+1)%n;
        if(vec[id].s < vec[id].f && vec[id].f != 1) pq.insert(id);
    }
    bool done = true;
    frange(i, n) {
        if(vec[i].f != vec[i].s) done = false;
    }
    if(done) printf("Yes\n");
    else printf("No\n");

}