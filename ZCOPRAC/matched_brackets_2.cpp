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

    stack<pii> stk;
    vi ma(n);

    vi out(2);

    frange(i, n) {
        int c;
        scd(c);
        c--;
        if(c % 2) {
            c /= 2;
            auto p = stk.top();
            stk.pop();
            out[c] = max(out[c], i - p.s + 1);
            if(stk.size()) {
                int v = (stk.top().f != c);
                ma[stk.top().s] = max(ma[stk.top().s], ma[p.s] + v);
            }
        }
        else {
            stk.push(mp(c/2, i));
            ma[i] = 1;
        }
    }

    printf("%d %d %d", *max_element(all(ma)), out[0], out[1]);
}