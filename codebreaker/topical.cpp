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

int rv[int(1e6+10)];
int upd[int(1e6)+10];

int main() {
    // usaco();
    fastio();
    int n, k;
    cin >> n >> k;

    vi cnt(n);
    vector<map<lli, vi>> val(k);
    

    frange(i, n) {
        frange(j, k) {
            cin >> rv[i*k+j];
            val[j][rv[i*k+j]].pb(i);
            if(rv[i*k+j] == 0) cnt[i]++;
        }
    }

    frange(i, n) {
        frange(j, k) {
            cin >> (upd[i*k+j]);
        }
    }

    int c = 0;
    queue<int> q;
    forr(i, 0, n) {
        if(cnt[i] == k) q.push(i);
    }
    vll skl(k);
    while(q.size()) {
        auto x = q.front();
        q.pop();
        c++;
        frange(j, k) {
            auto it1 = val[j].upper_bound(skl[j]);
            skl[j] += upd[x*k+j];
            auto it2 = val[j].upper_bound(skl[j]);
            while(it1 != it2) {
                for(auto e : (*it1).s) {
                    cnt[e]++;
                    if(cnt[e] == k) q.push(e);
                }
                it1++;
            }
        }
    }
    cout << c;
}