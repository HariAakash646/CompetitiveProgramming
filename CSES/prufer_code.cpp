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
    int n;
    scd(n);

    vi cnt(n+1);
    vi vec(n-2);
    frange(i, n-2) {
        int a;
        scd(a);
        cnt[a]++;
        vec[i] = a;
    }

    seti st;
    forr(i, 1, n+1) {
        if(cnt[i] == 0) st.insert(i);
    }

    for(auto e : vec) {
        printf("%d %d\n", e, *st.begin());
        st.erase(st.begin());
        cnt[e]--;
        if(!cnt[e]) st.insert(e);
    }

    printf("%d %d\n", *st.begin(), *next(st.begin()));
}