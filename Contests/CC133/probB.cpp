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

int main() {
    // usaco();
    fastio();
    int t;
    cin >> t;
    frange(_, t) {
        int n;
        string str;
        cin >> n >> str;

        vi pra(n+2), sfc(n+2);

        forr(i, 1, n+1) {
            pra[i] = pra[i-1] + (str[i-1] == 'a');
        }
        for(int i=n; i>=1; i--) {
            sfc[i] = sfc[i+1] + (str[i-1] == 'c');
        }

        int mi = 1e9;
        vi bpos;
        forr(i, 1, n+1) {
            if(str[i-1] == 'b') bpos.pb(i);
        }
        if(bpos.size() == 0) {
            printf("0\n");
            continue;
        }
        mi = min(pra[bpos.back()], sfc[bpos.front()]);
        forr(i, 0, (int)bpos.size() - 1) {
            mi = min(mi, pra[bpos[i]] + sfc[bpos[i+1]]);
        }
        printf("%d\n", mi);
    }
}