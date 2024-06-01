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
        int n, k;
        scd(n);
        scd(k);
        vector<pair<lli, lli>> vec(n);
        frange(i, n) sclld(vec[i].s);
        frange(i, n) sclld(vec[i].f);
        sort(all(vec));
        vector<pair<lli, int>> val(n);
        frange(i, n) val[i] = mp(vec[i].s, i);
        sort(all(val));
        vi pos(n);
        frange(i, n) {
            pos[val[i].s] = i;
        }
        lli al = 0;
        lli bob = 0;
        frange(i, k) al += val[i].f;
        int id = k-1;
        lli ma = 0;

        frange(i, n) {
            bob += max(0LL, vec[i].f-vec[i].s);
            int i1 = pos[i];
            if(i1 <= id) {
                al -= val[i1].f;
                id++;
                bool done = true;
                while(true) {
                    if(id >= n) {
                        done = false;
                        break;
                    }
                    if(!val[id].f) id++;
                    else break;
                }
                if(!done) break;
                else al += val[id].f;
            } 
            val[i1].f = 0;
            ma = max(ma, bob - al);
            // printf("%lld %lld\n", bob, al);
        }   
        printf("%lld\n", ma);
    }
}