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
        seti st;
        int tot = 0;
        st.insert(1);
        tot += 1;
        if(n % 3 == 0) {
            st.insert(4);
            tot += 4;
        }
        else {st.insert(2); tot += 2;}

        if(n - tot <= 0 || st.find(n-tot) != st.end()) {
            printf("NO\n");
        }
        else {
            printf("YES\n");
            st.insert(n-tot);
            for(auto e : st) {
                printf("%d ", e);
            }
            printf("\n");
        }
    }
}