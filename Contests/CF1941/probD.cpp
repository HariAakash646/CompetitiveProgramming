#include <bits/stdc++.h>
 
using namespace std;
 
#define scd(t) scanf("%d", &t)
#define sclld(t) scanf("%lld", &t)
#define forr(i, l, r) for(int i=l; i<r; i++)
#define frange(i, l) forr(i, 0, l)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()
 
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef long long lli;
typedef vector<vi> vvi;
typedef vector<lli> vll;
typedef vector<bool> vb;
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
        int n, m, x;
        cin >> n >> m >> x;
        seti curr;
        curr.insert(x);

        frange(i, m) {
            int c;
            char d;
            cin >> c >> d;
            seti nxt;
            if(d != '1') {
                for(auto e : curr) nxt.insert((e + c - 1) % n + 1);
            }
            if(d != '0') {
                for(auto e : curr) nxt.insert((e + (n-c) - 1) % n + 1);
            }
            curr = nxt;
        }
        cout << curr.size() << "\n";
        for(auto e : curr) cout << e << " ";
        cout << "\n";
    }
}