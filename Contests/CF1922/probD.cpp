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
        int n;
        scd(n);

        vii vec(n);

        frange(i, n) scd(vec[i].f);
        frange(i, n) scd(vec[i].s);

        seti st;
        seti curr;
        frange(i, n) {
            st.insert(i);
            curr.insert(i);
        }
        frange(i, n) {
            // printf("%d %d : ", _, i);
            // for(auto e : st) printf("%d ", e);
            // printf("\n");
            seti rem;
            int c = 0;
            for(auto e : curr) {
                int v = 0;
                auto it = st.find(e);
                // printf("val: %d ", e);
                if(it != st.begin()) {
                    v += vec[*prev(it)].f;
                    // printf("%d ", *prev(it));
                }
                if(it != prev(st.end())) {
                    v += vec[*next(it)].f;
                    // printf("%d ", *next(it));
                }
                // printf("%d\n", v);
                if(v > vec[e].s) {c++;
                                    rem.insert(e);}
            }            
            printf("%d ", c);
            curr = {};
            for(auto e : rem) {
                auto it = st.find(e);
                if(it != st.begin()) {
                    curr.insert(*prev(it));
                }
                if(it != prev(st.end())) {
                    curr.insert(*next(it));
                }
                st.erase(it);
            }
            rem = {};
            for(auto e : curr) {
                if(st.find(e) == st.end()) rem.insert(e);
            }
            for(auto e : rem) curr.erase(e);
        }
        
        printf("\n");

    }
}