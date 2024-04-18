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
    int n, q;
    scd(n);
    scd(q);

    vi vec(n+1);
    vi pos(n+1);

    forr(i, 1, n+1) {
        scd(vec[i]);
        pos[vec[i]] = i;
    }

    lli tot = 0;
    int st = 0;

    forr(i, 1, n+1) {
        if(pos[i] > st) {
            tot += pos[i] - i + 1;
            st = pos[i];
        }
        else tot++;
    }
    printf("%lld ", tot);

    vi v2 = vec;
    vi pos2 = pos;

    frange(_, q) {
        int v;
        scd(v);

        v2.erase(find(all(v2), vec[v]));

        vi v3 = v2;
        sort(all(v3));

        vi val(n+1);

        forr(i, 1, v3.size()) {
            val[v3[i]] = i;
        }

        vi pos2(v3.size());

        forr(i, 1, v3.size()) {
            pos2[val[v2[i]]] = i;
        }

        lli tot = 0;
        int st = 0;

        forr(i, 1, v3.size()) {
            if(pos2[i] > st) {
                tot += pos2[i] - i + 1;
                st = pos2[i];
            }
            else tot++;
        }
        printf("%lld ", tot);




    }
}