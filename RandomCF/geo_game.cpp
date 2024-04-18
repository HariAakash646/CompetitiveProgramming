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

multiset<int> eve, odd;

void play() {
    if(!odd.size()) swap(odd, eve);
    auto it = odd.begin();
    printf("%d\n", *it);
    fflush(stdout);
    odd.erase(it);
}

bool opp() {
    int id;
    scd(id);
    if(id == -1) return false;
    auto it = odd.find(id);
    if(it != odd.end()) odd.erase(it);
    else {
        it = eve.find(id);
        eve.erase(it);
    }
    return true;
} 

int main() {
    int t;
    scd(t);

    frange(_, t) {
        int n;
        scd(n);

        int x, y;
        scd(x);
        scd(y);

        eve = {};
        odd = {};

        frange(i, n) {
            int x1, y1;
            scd(x1);
            scd(y1);

            if((abs(x1-x) + abs(y1-y)) % 2) odd.insert(i+1);
            else eve.insert(i+1);
        }
        bool done = true;
        if(eve.size() >= odd.size()) {
            printf("First\n");
            fflush(stdout);
            if(n % 2) {
                play();
                frange(i, n/2) {
                    if(!opp()) return 0; 
                    play();
                }
            }
            else {
                frange(i, n/2) {
                    play();
                    if(!opp()) return 0; 
                }
            }
        }
        else {
            printf("Second\n");
            fflush(stdout);
            swap(odd, eve);

            if(n % 2) {
                if(!opp()) return 0; 
                frange(i, n/2) {
                    play();
                    if(!opp()) return 0; 
                }
            }
            else {
                frange(i, n/2) {
                    
                    if(!opp()) return 0; 
                    play();
                }
            }

        }
    }
}