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
    int t;
    scd(t);
    frange(_, t) {
        int n, m;
        scd(n);
        scd(m);
        string s1, s2;
        cin >> s1 >> s2;

        bool g1 = true;
        bool g2 = true;
        bool done = false;
        int v=-1;

        forr(i, 1, n) {
            if(s1[i] == s1[i-1]) {
                g1 = false;
                if(v == -1) v = s1[i] - '0';
                else {
                    if(v != s1[i] - '0') {
                        done = true;
                        break;
                    }
                }
            }
        }

        if(g1) {printf("YES\n");continue;}
        if(done) {printf("NO\n");continue;}

        forr(i, 1, m) {
            if(s2[i] == s2[i-1]) g2 = false;
        }

        if(s2[0] != s2[m-1]) g2 = false;
        int v2 = s2[0] - '0';

        if(g2 && v != v2) printf("YES\n");
        else printf("NO\n");
    }
}