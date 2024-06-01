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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int query(int l, int r) {
    printf("? %d %d\n", l, r);
    fflush(stdout);
    int v;
    scd(v);
    return v;
}

int main() {
    fastio();
    int n = 1000;
    vi pos(n+1);
    vi val(n+1);
    pos[1] = 1;
    val[1] = 1;

    vvi vec(n+1, vi(n+1, -1));
    forr(i, 1, n+1) vec[i][i] = 0;

    forr(i, 2, n+1) {
        int v = query(i-1, i);
        vec[i-1][i] = v;
        pii p;
        if(v) p = mp(1, pos[i-1]);
        else p = mp(pos[i-1]+1, i);
        for(int j=i-2; j>=1; j--) {
            if(p.f <= pos[j] && pos[j] < p.s) {
                int v = query(j, i);
                vec[j][i] = v;
                if(vec[j][i-1] == -1) vec[j][i-1] = query(j, i-1);
                if(vec[j+1][i] == -1) vec[j+1][i] = query(j+1, i);
                if(vec[j+1][i-1] == -1) vec[j+1][i-1] = query(j+1, i-1);
                int v1 = (vec[j][i-1] + vec[j+1][i] - vec[j+1][i-1] + 2) % 2;
                if(v != v1) {
                    p = mp(p.f, pos[j]);
                }
                else {
                    p = mp(pos[j]+1, p.s);
                }
            }
        }
        forr(j, p.f, i) {
            pos[val[j]]++;
        }
        pos[i] = p.f;
        forr(j, 1, i+1) {
            val[pos[j]] = j;
        }
    } 
    printf("!\n");
    forr(i, 1, n+1) printf("%d ", pos[i]);
    printf("\n");
}