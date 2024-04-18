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
    int n;
    scd(n);

    vll vec(n);

    frange(i, n) sclld(vec[i]);


    multiset<lli> st;

    frange(i, n) {
        st.insert(vec[i] + i);
    }

    lli mi = 2e9 + 5;
    frange(i, n) {
        st.erase(st.find(vec[i] + i));
        lli v = vec[i];

        if(st.size()) v = max(v, *prev(st.end()));
        mi = min(mi, v);

        st.insert(vec[i] + n - i - 1);

    }

    printf("%lld", mi);
}