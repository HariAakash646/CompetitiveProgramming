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
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);
        printf("+ %d\n", n);
        fflush(stdout);
        int v;
        scd(v);
        if(v == -2) return 0;
        printf("+ %d\n", n+1);
        fflush(stdout);
        scd(v);
        if(v == -2) return 0;

        vi vec;
        int en = n;
        int st = 1;
        frange(i, n) {
            if(i%2==0) {
                vec.pb(en);
                en--;
            }
            else {
                vec.pb(st);
                st++;
            }
            // printf("%d ", vec[i]);
        }
        // printf("\n");
        // fflush(stdout);
        vi val(n+1);
        pii ma = mp(0, 0);
        int x = 1;

        forr(i, 2, n+1) {
            printf("? %d %d\n", 1, i);
            fflush(stdout);
            int v;
            scd(v);
            if(v == -2) return 0;
            
            ma = max(ma, mp(v, i));
        }

        x = ma.s;
        val[x-1] = 0;
        forr(i, 1, n+1) {
            if(x == i) continue;
            printf("? %d %d\n", x, i);
            fflush(stdout);
            int v;
            scd(v);
            if(v == -2) return 0;
            val[i-1] = v;
        }

        printf("! ");
        frange(i, n) {
            printf("%d ", vec[val[i]]);
        }
        reverse(all(vec));
        frange(i, n) {
            printf("%d ", vec[val[i]]);
        }
        printf("\n");
        fflush(stdout);
        scd(v);
        if(v==-2) return 0;
    }
}