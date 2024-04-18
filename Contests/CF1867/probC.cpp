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
    freopen("input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

int main() {
    int t;
    scd(t);
    frange(_, t) {
        int n;
        scd(n);
        seti st;
        frange(i, n) {
            int a;
            scd(a);
            st.insert(a);
        }
        int c=n;
        int x = 0;
        auto it = st.begin();
        frange(i, n) {
            if(*it == i || *it == i+1) {it++;continue;}
            else {
                // printf("%d %d\n", i+1, *it);
                c = i;
                break;
            }
        }
        while(true) {
            // printf("%d\n", c);
            // fflush(stdout);
            for(int i=c; i>=0; i--) {
                if(st.find(i) == st.end()) {
                    c = i;
                    break;
                }
            }
            st.insert(c);
            printf("%d\n", c);
            fflush(stdout);
            int v;
            scd(v);
            if(v == -1) break;
            if(v == -2) return 0;
            st.erase(v);
            
        }
    }
}