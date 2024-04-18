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
        int n, m;
        scd(n);
        scd(m);

        vvi vec(m, vi(n));

        set<vi> st;

        frange(i, m) {
            frange(j, n) scd(vec[i][j]);
            st.insert(vec[i]);
        }

        if(st.size() != m) {
            printf("0\n\n");
            continue;
        }

        vector<seti> val(n);
        vi curr;

        frange(i, m) curr.pb(i);

        frange(i, n) {
            mpii cnt;

            frange(j, m) {
                cnt[vec[j][i]]++;
            }
            vi tmp;
            for(auto e : curr) {
                if(cnt[vec[e][i]] == m/2) tmp.pb(e);
            }
            curr = tmp;
        }
        bool done = true;
        if(curr.size()) {
            vi v = vec[curr[0]];
            vb pres(m);

            frange(i, m) {
                int curr = 0;
                frange(j, n) {
                    if(vec[i][j] != v[j]) curr += (1<<j);
                }
                pres[curr] = true;
            }

            
            frange(i, m) {
                if(!pres[i]) done = false;
            }
        }

        if(!done) {
            printf("0\n\n");
            continue;
        }

        // for(auto e : curr) st.insert(vec[e]);

        // if(st.size() != curr.size()) {
        //     printf("0\n\n");
        //     continue;
        // }

        printf("%d\n", (int)curr.size());
        for(auto e : curr) printf("%d ", e);
        printf("\n");

    }
}