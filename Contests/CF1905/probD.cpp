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
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);

        vi vec(n);
        int zer;
        frange(i, n) {
            scd(vec[i]);
            if(vec[i] == 0) zer = i;
        }

        vi v2;

        forr(i, zer, n) v2.pb(vec[i]);
        forr(i, 0, zer) v2.pb(vec[i]);
        seti st;
        frange(i, n) st.insert(i);

        vll val(n);
        val[0] = 1;
        st.erase(0);
        forr(i, 1, n) {
            val[i] = val[i-1] + *st.begin() + 1;
        }

        int curr = n-1;
        lli ma = val[n-1];
        int id = n-1;
        while(id >=0) {
            id--;
            if(vec[id] < curr) {
                lli tot = val[id] + (curr-id) * (vec[curr]+1);
                curr = id ;
                ma = max(ma, tot);
                break;
            }
        }

        printf("%lld\n", ma);






    }
}