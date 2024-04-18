#include <bits/stdc++.h>

using namespace std;

#define scd(t) scanf("%d", &t)
#define scld(t) scanf("%ld", &t)
#define sclld(t) scanf("%lld", &t)
#define scc(t) scanf("%c", &t)
#define scs(t) scanf("%s", t)
#define scf(t) scanf("%f", &t)
#define sclf(t) scanf("%lf", &t)
#define forr(i, j, k) for (int i = j; i < k; i++)
#define frange(i, j) forr(i, 0, j)
#define all(cont) cont.begin(), cont.end()
#define mp make_pair
#define pb push_back
#define f first
#define s second
typedef long int li;
typedef unsigned long int uli;
typedef long long int lli;
typedef unsigned long long int ulli;
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
    stack<int> stk1, stk2;
    stk1.push(1e9);
    stk2.push(1e9);
    int v = 1;
    vi out;
    frange(i, n) {
        int a;
        scd(a);
        if(stk1.top() > a && (stk2.top() < a || stk1.top() <= stk2.top()))
            {stk1.push(a); out.pb(1);}
        else if(stk2.top() > a) {stk2.push(a); out.pb(2);}
        else {
            printf("NIE");
            return 0;
        }
        while(stk1.top() == v || stk2.top() == v) {
            if(stk1.top() == v) {
                stk1.pop();
                v++;
            }
            if(stk2.top() == v) {
                stk2.pop();
                v++;
            }
        }
    }
    if(stk1.size()>1 || stk2.size()>1) {
        printf("NIE");
    }
    else {
        printf("TAK\n");
        for(auto e : out) printf("%d ", e);
    }
}