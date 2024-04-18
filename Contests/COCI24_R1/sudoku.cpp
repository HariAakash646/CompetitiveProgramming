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
    vvi grid(9, vi(9));

    string str;
    cin >> str;
    int i1 = 0;
    frange(i, 11) {
        string str;
        cin >> str;
        if(i != 3 && i != 7) {
            int id = 0;
            for(auto e : str) {
                if(e != '|') {
                    if(e == '.') grid[i1][id] = 0;
                    else grid[i1][id] = e - '0';
                    id++;
                }
            }
            i1++;
        }
    }

    bool done = true;
    frange(i, 9) {
        seti st;
        for(auto e : grid[i]) {
            if(e) {
                if(st.find(e) != st.end()) done = false;
                st.insert(e);
            }
        }
    }

    frange(j, 9) {
        seti st;
        frange(i, 9) {
            int e = grid[i][j];
            if(e) {
                if(st.find(e) != st.end()) done = false;
                st.insert(e);
            }
        }
    }

    frange(i, 3) {
        frange(j, 3) {
            seti st;
            frange(k, 3) {
                frange(l, 3) {
                    int e = grid[3*i+k][3*j+l];
                    if(e) {
                        if(st.find(e) != st.end()) done = false;
                        st.insert(e);
                    }
                    
                }
            }
        }
    }
    if(done) printf("OK");
    else printf("GRESKA");
}