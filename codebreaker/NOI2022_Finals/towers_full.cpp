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
    int n;
    scd(n);

    vii vec(n);
    vector<set<pii>> row(1e6+1), col(1e6+1);
    vector<pii> colv(1e6+1);

    frange(i, n) {
        scd(vec[i].f);
        scd(vec[i].s);
        row[vec[i].f].insert(mp(vec[i].s, i));
        col[vec[i].s].insert(mp(vec[i].f, i));
    }

    forr(i, 1, 1e6+1) {
        if(row[i].size()) {
            auto p = *row[i].begin();
            colv[p.f] = mp(i, p.s);
            p = *prev(row[i].end());
            colv[p.f] = mp(i, p.s);
        }
    }
    vi out(n);
    forr(i, 1, 1e6+1) {
        if(row[i].size()) {
            if(row[i].size() > 1) {
                auto it1 = prev(row[i].end());
                auto p = *it1;
                out[p.s] = 1;
                // printf("%d ", p.s);
                auto it = prev(col[vec[p.s].s].end());

                // printf("%d\n", colv[vec[p.s].s].s);
                // it++;
                auto it2 = col[vec[p.s].s].find(mp(i, p.s));
                while(it != it2) {
                    // printf("%d\n", (*it).s);
                    if(*row[(*it).f].begin() == mp(vec[p.s].s, (*it).s) || *prev(row[(*it).f].end()) == mp(vec[p.s].s, (*it).s)) {
                        it--;
                        break;
                    }
                    // row[(*it).f].erase(mp(vec[p.s].s, (*it).s));
                    // printf("%d\n", (*it).s);
                    it--;
                    
                }
                while(it!= it2) {
                    row[(*it).f].erase(mp(vec[p.s].s, (*it).s));
                    it--;
                }
                // col[vec[p.s].s] = {};
            }
            auto it1 = row[i].begin();
            auto p = *it1;
            out[p.s] = 1;
            // printf("%d ", p.s);
            // printf("%d\n", colv[vec[p.s].s].f);
            auto it = prev(col[vec[p.s].s].end());

                // printf("%d\n", colv[vec[p.s].s].s);
                // it++;
            auto it2 = col[vec[p.s].s].find(mp(i, p.s));
            while(it != it2) {
                // printf("%d\n", (*it).s);
                if(*row[(*it).f].begin() == mp(vec[p.s].s, (*it).s) || *prev(row[(*it).f].end()) == mp(vec[p.s].s, (*it).s)) {
                    it--;
                    break;
                }
                // row[(*it).f].erase(mp(vec[p.s].s, (*it).s));
                // printf("%d\n", (*it).s);
                it--;
            }
            while(it!= it2) {
                row[(*it).f].erase(mp(vec[p.s].s, (*it).s));
                it--;
            }
            // col[vec[p.s].s] = {};
        }
    }
    frange(i, n) printf("%d", out[i]);
}