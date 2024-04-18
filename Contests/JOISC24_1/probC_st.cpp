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
    usaco();
    int n;
    lli c;
    scd(n);
    sclld(c);

    vector<pair<lli, lli>> vec(n);
    frange(i, n) {
        sclld(vec[i].f);
        sclld(vec[i].s);
    }

    sort(all(vec));

    if(c >= 1e5) {
        lli v = 0;
        vb occ(n);
        forr(i, 1, n) {
            bool done = false;
            lli v1 = 1e18;
            for(int j=i-1; j>=0; j--) {
                if(vec[i].f > vec[j].f) {
                    done = true;
                    if(!occ[j]) {
                        v1 = 0;
                        occ[j] = true;
                        break;
                    }
                    else {
                        v1 = min(v1, vec[j].s);
                    }
                }
            }
            if(!done) {

                v1 = 1e18;
                for(int j=i-1; j>=0; j--) {
                    if(!occ[j] && vec[i].f >= vec[j].f) {
                        v1 = 0;
                        occ[j] = true;
                        break;
                    }
                    else if(vec[i].f >= vec[j].f) {
                        v1 = min(v1, vec[j].s);
                    }
                }
                v1 += c;
                vec[i].f++;
            }
            // printf("%lld ", v1);
            v += v1;
        }
        printf("%lld", v);
    }
    else {
        lli v = 0;
        seti st;
        st.insert(vec[0].f);
        forr(i, 1, n) {
            lli v1 = 0;
            lli b1 = 0;
            
            v1 = c * max(0LL, vec[0].f - vec[i].f + 1) + vec[0].s;
            b1 = max(0LL, vec[0].f -vec[i].f + 1);
            lli h = *st.begin();
            lli v2 = c * max(0LL, h - vec[i].f+ 1);
            lli b2 = max(0LL, h-vec[i].f + 1);
            
            if(v1 < v2) { v+=v1; vec[i].f+=b1;}
            else {
                v += v2;
                st.erase(st.begin());
                vec[i].f += b2;
            }
            printf("%lld ", min(v1, v2));
            st.insert(vec[i].f);
        }
        printf("%lld", v);
    }
}