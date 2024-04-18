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
    forr(i, 10000, 100000) {
        string st = "";
        int v = i;
        frange(_, 5) {
            st += char('0' + v % 10);
            v/=10;
        }
        vi out;
        do {
            int x = stoi(st);
            if(int(sqrt(x)) * int(sqrt(x)) == x) out.pb(x);
        }
        while(next_permutation(all(st)));
        if(out.size() >= 5) {
            for(auto e : out) printf("%d ", e);
            printf("\n");
        }
        
    }
}