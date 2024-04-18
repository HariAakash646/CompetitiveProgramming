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
        int k;
        scd(k);

        vll vec(n);

        set<lli> st;
        frange(i, n) {
            sclld(vec[i]);
            st.insert(vec[i]);
        }

        if(k >= 3) {
            printf("0\n");
            continue;
        }
        else {
            if(k == 1) {
                lli mi = *st.begin();
                frange(i, n) {
                    forr(j,i+1, n) {
                        mi = min(mi, abs(vec[i]-vec[j]));
                    }
                }
                printf("%lld\n", mi);
            }
            else {
                lli mi = *st.begin();
                frange(i, n) {
                    forr(j,i+1, n) {
                        mi = min(mi, abs(vec[i]-vec[j]));
                        lli v1 = abs(vec[i]-vec[j]);
                        auto it = st.lower_bound(v1);
                        lli v = 2e18;
                        if(it != st.end())
                        mi = min(mi, abs(*it - v1));
                        if(it != st.begin()) {
                            it--;
                            mi = min(mi, abs(*it - v1));
                        }
                    }
                }
                printf("%lld\n", mi);
            }
        }

    }
}