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

void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void usaco()
{
    freopen("input.in", "r", stdin);
//    freopen("problem.out", "w", stdout);
}

vi cnt1, cnt2;

bool dfs(vector<string> &v1, vector<string> &v2, int i1, int& i2, bool fir) {
    if(fir) {
        if(cnt1[i1] != -1) return cnt1[i1];
    }
    else {
        if(cnt2[i1] != -1) return cnt2[i1];
    }
    string str = v1[i1];
    bool out = true;
    int ogi1 = i1;
    bool pre = false;
    forr(i, i2, v2.size()) {
        if(v2[i] > str) {
            if(!pre) {
                i2 = i;
                pre = true;
            }
            if(v2[i][0] - str[0] <= 1) {
                out = out && (!dfs(v2, v1, i, i1, !fir));
            }
            else break;
        }
    }
    i1 = ogi1;
    if(fir) cnt1[i1] = out;
    else cnt2[i1] = out;
    return out;
}

int main() {
    fastio();
    // usaco();
    int n, m;
    cin >> n >> m;
    vector<string> v1(n), v2(m);
    frange(i, n) cin >> v1[i];
    frange(i, m) cin >> v2[i];
    sort(all(v1));
    sort(all(v2));
    cnt1 = vi(n, -1);
    cnt2 = vi(m, -1);
    int v = 0;
    bool out = dfs(v1, v2, 0, v, true);

    if(out) cout<<("Leona\n");
    else cout<<("Zoe\n");
}