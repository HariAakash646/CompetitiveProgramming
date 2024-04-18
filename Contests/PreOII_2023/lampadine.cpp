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

int N;
int query;
vector<bool> used;
vector<int> lampadine;
vector<vector<int>> gruppi;
vector<vector<int>> ans;

// vector<int> disconnect(vector<int> svitate) {
//     query++;
    
//     vector<int> query(N, 0);

//     for (auto l: svitate) {
//         if (l < 0 || l >= N) {
//             cout << "Richiesta malformata. / Malformed query." << endl;
//             exit(1);
//         }
//         if (query[l]) {
//             cout << "Richiesta malformata. / Malformed query." << endl;
//             exit(1);
//         }
//         query[l] = 1;
//     }

//     vector<int> ans(N, 1);
//     for (int i = 0; i < N; i++) {
//         if (query[i] && ans[i]) {
//             for (auto l: gruppi[lampadine[i]]) {
//                 ans[l] = 0;
//             }
//         }
//     }

//     return ans;
// }

// void series(vector<int> lampadine) {
//     if (lampadine.empty()) {
//         cout << "Serie malformata. / Malformed series." << endl;
//         exit(1);
//     }

//     for (auto lampadina: lampadine) {
//         if (used[lampadina]) {
//             cout << "Serie malformata. / Malformed series." << endl;
//             exit(1);
//         }
//         used[lampadina] = true;
//     }

//     ans.push_back(lampadine);
// }

vector<int> disconnect(vector<int> L);
void series(vector<int> G);

void study(int n) {
    vector<pair<vi, int>> val(1);

    frange(i, n) val[0].f.pb(i);
    val[0].s = 1;
    int x = n;
    while(x) {
        x = x/2;
        vi off;
        for(auto p : val) {
            auto v = p.f;
            int c = p.s;
            frange(i, min(x+1, ((int)v.size())/2)) {
                off.pb(v[i]);
            }
        }
        vi out = disconnect(off);
        vector<pair<vi, int>> tmp;
        for(auto p : val) {
            auto v = p.f;
            int c = p.s;
            vi v1, v2;
            for(auto e : v) {
                if(out[e]) {
                    v1.pb(e);
                }
                else v2.pb(e);
            }
            if(v1.size()) tmp.pb(mp(v1, 1));
            if(v2.size()) tmp.pb(mp(v2, c+1));
        }
        val = tmp;
        
    }
    for(auto p : val) series(p.f);
}

// int main() {
//     // decommenta queste due righe per leggere da / scrivere su file
//     // uncomment these two lines to read from / write to file
//     // assert(freopen("input.txt", "r", stdin));
//     // assert(freopen("output.txt", "w", stdout));
//     usaco();
//     cin >> N;

//     lampadine.resize(N);
//     used.resize(N);
//     for (auto &l: lampadine) cin >> l;

//     gruppi.resize(1 + *max_element(lampadine.begin(), lampadine.end()));
//     for (int i = 0; i < N; i++) {
//         gruppi[lampadine[i]].push_back(i);
//     }

//     study(N);

//     cout << query << endl;
//     cout << ans.size() << endl;
//     for (auto group: ans) {
//         cout << group.size() << " ";
//         for (auto elem: group) {
//             cout << elem << " ";
//         }
//         cout << endl;
//     }
// }