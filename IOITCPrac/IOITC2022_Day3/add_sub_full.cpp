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

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

struct Out {
    int k;
    vi vec;
    int id;
    char c='+';
};

int main() {
    // usaco();
    int n;
    cin >> n;
    vll vec(n+1);

    int g = 0;
    map<int, vi> st;
    forr(i, 1, n+1) {
        cin >> vec[i];
        g = gcd(g, vec[i]);
        st[vec[i]].pb(i);
    }
    if(st.size()<=700) {
        printf("%d\n", (int)st.size());
        for(auto p : st) {
            printf("%d\n", (int)p.s.size());
            for(auto e : p.s) {
                printf("%d ", e);
            }
            printf("\n");
            printf("- %d\n", p.s[0]);
        }
        return 0;
    }
    vii v2;
    forr(i, 1, n+1) {
        vec[i] /= g;
        v2.pb(mp(vec[i], i));
    }
    sort(all(v2));
    vb mult(1e5+1);
    mult[0] = true;
    // for(auto e : vec) {
    //     for(int i=1; i*e<=1e5; i++) {
    //         mult[i*e]= true;
    //     }
    // }
    pii p = mp(-1, -1);
    forr(i, 0, n) {
        forr(j, i+1, n) {
            
            int v = v2[j].f - v2[i].f - 1;
            // printf("%d %d\n", v2[j].f, v2[i].f);
            if(mult[v]) {
                p = mp(v2[i].s, v2[j].s);
                break;
            }
            
        }
        int e = v2[i].f;
        if(e) {
            for(int i=1; i*e<=1e5; i++) {
                mult[e*i] = true;
            }
        }
    }
    vector<Out> out;
    int v = vec[p.s] - vec[p.f]-1;
    forr(i, 1, n+1) {

        if(i != p.f && i != p.s && vec[i] != 0 && v % vec[i] == 0) {
            int c = v/vec[i];
            frange(j, 20) {
                Out curr;
                if(c & (1<<j)) {
                    curr.k = 2;
                    curr.vec.pb(i);
                    curr.vec.pb(p.f);
                    curr.id = i;
                }
                else {
                    curr.k = 1;
                    curr.vec.pb(i);
                    curr.id = i;
                }
                out.pb(curr);
                vec[i] *= 2;
            }
            break;
        }
    }
    Out curr;
    curr.k = 2;
    curr.vec = {p.f, p.s};
    curr.id = p.f;
    curr.c = '-';
    out.pb(curr);
    vec[p.s] = 1;
    vec[p.f] = 0;

    seti nz;
    forr(i, 1, n+1) {
        if(vec[i]) nz.insert(i);
    }

    vvi idx(60);
    lli vt = (1LL<<59);

    for(auto i : nz) {
        if(i==p.s) continue;
        lli x = vt-vec[i];
        frange(j, 60) {
            if(x&(1LL<<j)) idx[j].pb(i);
        }
    }

    frange(j, 60) {
        Out curr;
        curr.k = 1 + idx[j].size();
        curr.vec.pb(p.s);
        for(auto e : idx[j]) curr.vec.pb(e);
        curr.id = p.s;
        out.pb(curr);
    }

    curr.k = nz.size();
    for(auto e : nz) curr.vec.pb(e);
    curr.id = p.s;
    curr.c = '-';
    out.pb(curr);

    cout << out.size() << "\n";

    for(auto p : out) {
        printf("%d\n", p.k);
        for(auto e : p.vec) printf("%d ", e);
        printf("\n");
        printf("%c %d\n", p.c, p.id);
    }



}