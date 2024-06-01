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

bool cmp(pii x, pii y) {
    if(x.f + x.s == y.f + y.s) return x.s > y.s;
    else
    return x.f + x.s > y.f + y.s;
}

int main() {
    // usaco();
    int t;
    scd(t);

    frange(_, t) {
        int n, k;
        scd(n);
        scd(k);
        pii p;
        scd(p.f);
        scd(p.s);
        vii vec(n-1);
        mseti st;
        frange(i, n-1) {
            scd(vec[i].f);
            scd(vec[i].s);
            st.insert(vec[i].f);
        }
        if(k <= p.f) {printf("YES\n");continue;}
        if(n == 1) {
            
            printf("NO\n");
            continue;
        }
        lli curr = k-p.s;
        sort(all(vec), cmp);
        bool done = false;
        if(curr > p.f) {
            printf("NO\n");
            continue;
        }
        priority_queue<pii> st2;
        int id = 0;
        frange(i, n-1) {
            
            if(curr <= *prev(st.end())) {done = true; break;}
            while(id < n-1 && vec[id].f + vec[id].s >= curr) {st2.push(mp(vec[id].s, vec[id].f));id++;}
            if(st2.empty()) break;
            auto p = st2.top();
            st2.pop();
            curr -= p.f;
            st.erase(st.find(p.s));
        }

        if(done) printf("YES\n");
        else printf("NO\n");
    }
}