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
    fastio();
    // usaco();
    int t;
    cin >> t;

    frange(_, t) {
        int n, m;
        cin >> n >> m;
        string str1, str2;
        cin >> str1 >> str2;
        vector<queue<int>> vec(26);

        frange(i, n) {
            vec[str1[i]-'a'].push(i);
        }
        bool done = true;
        frange(i, m) {
            int c = str2[i] - 'a';
            if(vec[c].empty()) {
                done = false;
                break;
            }
            int id = vec[c].front();
            // cout << id << " ";
            vec[c].pop();
            frange(j, c) {
                while(vec[j].size() && vec[j].front() < id) vec[j].pop();
            }
        }
        if(done) cout<<("YES\n");
        else cout<<("NO\n");
    }
}