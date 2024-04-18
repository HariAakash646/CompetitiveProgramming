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
        int n, q;
        scd(n);
        scd(q);

        vii oper(n);
        frange(i, n) {
            scd(oper[i].f);
            scd(oper[i].s);
        }

        vector<pair<lli, int>> quer(q);
        frange(i, q) {
            sclld(quer[i].f);
            quer[i].s = i;
        }

        sort(all(quer));
        int id = 0;

        __int128 curr = 0;

        vector<vll> prop;
        vi out(q);

        for(auto p : oper) {
            if(p.f == 1) {
                curr++;
                if(prop.size() && prop[prop.size()-1][0] != -1) {
                    prop[prop.size()-1].pb(p.s);
                }
                else {
                    vll val;
                    val.pb(p.s);
                    prop.pb(val);
                }
            }
            else {
                curr *= (p.s+1);
                vll val;
                val.pb(-1);
                val.pb(p.s+1);
                prop.pb(val);
            }
            // printf("%lld\n", curr);
            while(id < q && quer[id].f <= curr) {

                auto p = quer[id];
                __int128 x = quer[id].f;
                int v = prop.size()-1;
                __int128 c = curr;
                // printf("%d\n", p.s);
                while(v>=0) {
                    // printf("%lld %lld\n", x, c);
                    if(prop[v][0] == -1) {
                        x-=1;
                        x %= (c/prop[v][1]);
                        x += 1;
                        c /= prop[v][1];
                        
                    }
                    else {
                        if(x + (int)prop[v].size() > c) {
                            out[p.s] = prop[v][(int)prop[v].size()-(c-x)-1];
                            break;
                        }
                        else {
                            c -= (int)prop[v].size();
                        }
                    }
                    v--;
                }
                // printf("**************\n");
                id++;
            } 
            if(id == q) break;

        }
        for(auto e : out) printf("%d ", e);
        printf("\n");
    }
}